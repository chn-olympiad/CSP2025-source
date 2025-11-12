#include<bits/stdc++.h>
using namespace std;

int T;

struct Node{
    int c1;
    int c2;
    int c3;
    int MAX;
}like[100010];

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--){
        int n,l1 = 0,l2 = 0,l3 = 0;
        memset(like,0,sizeof(like));
        int num = 0;
        cin >> n;
        for(int i = 1;i <= n;i++){
            cin >> like[i].c1 >> like[i].c2 >> like[i].c3;
            like[i].MAX = max(like[i].c1,max(like[i].c2,like[i].c3));
            num += like[i].MAX;
        }
        for(int i = 1;i <= n;i++){
            if(like[i].MAX == like[i].c1){
                l1++;
            }
            else if(like[i].MAX == like[i].c2){
                l2++;
            }
            else{
                l3++;
            }
        }
        if(l1 <= n / 2 && l2 <= n / 2 && l3 <= n / 2){
            cout << num;
        }
        else{
            int mm[100010] = {0},cnt = 1;
            if(l1 > n / 2){
                for(int i = 1;i <= n;i++){
                    if(like[i].MAX == like[i].c1){
                        mm[cnt++] = min(like[i].c1 - like[i].c2,like[i].c1 - like[i].c3);
                    }
                }
                sort(mm + 1,mm + cnt);
                for(int i = 1;i <= l1 - n / 2;i++){
                    num -= mm[i];
                }
                cout << num;
            }
            else if(l2 >= n / 2){
                for(int i = 1;i <= n;i++){
                    if(like[i].MAX == like[i].c2){
                        mm[cnt++] = min(like[i].c2 - like[i].c1,like[i].c2 - like[i].c3);
                    }
                }
                sort(mm + 1,mm + cnt);
                for(int i = 1;i <= l2 - n / 2;i++){
                    num -= mm[i];
                }
                cout << num;
            }
            else{
                for(int i = 1;i <= n;i++){
                    if(like[i].MAX == like[i].c3){
                        mm[cnt++] = min(like[i].c3 - like[i].c2,like[i].c3 - like[i].c1);
                    }
                }
                sort(mm + 1,mm + cnt);
                for(int i = 1;i <= l3 - n / 2;i++){
                    num -= mm[i];
                }
                cout << num;
            }
        }
        cout << endl;
    }

    return 0;
}
