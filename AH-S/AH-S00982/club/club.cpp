#include<bits/stdc++.h>
using namespace std;
struct sb{
    int number;
    int p;
    int one_two;
    int one_three;
    int two_three;
    int two_one;
    int three_one;
    int three_two;
};
int n;
int t;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[100005][5];
        int b[100005];
        sb c[100005];
        int one = 0;
        int two = 0;
        int three = 0;
        int sum = 0;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=3;j++){
                cin >> a[i][j];
            }
            c[i].one_two = a[i][2]-a[i][1];
            c[i].one_three = a[i][3]-a[i][1];
            c[i].two_three = a[i][3]-a[i][2];
            c[i].two_one = a[i][1]-a[i][2];
            c[i].three_one = a[i][1]-a[i][3];
            c[i].three_two = a[i][2]-a[i][3];
        }
        for(int i = 1;i<=n;i++){
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
                c[i].p = 1;
                c[i].number = a[i][1];
                sum = sum+a[i][1];
                one++;
            }else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
                c[i].p = 2;
                c[i].number = a[i][2];
                sum = sum+a[i][2];
                two++;
            }else{
                c[i].p = 3;
                c[i].number = a[i][3];
                sum = sum+a[i][3];
                three++;
            }
        }
        if(one <= n/2 && two <= n/2 && three <= n/2){
            cout << sum << endl;
            continue;
        }
        int change;
        int xb = 0;
        if(one > n/2){
            change = one - n/2;
            for(int i = 1;i<=n;i++){
                if(c[i].p == 1){
                    b[xb] = max(c[i].one_two,c[i].one_three);
                    xb++;
                }
            }
        }else if(two > n/2){
            change = two - n/2;
            for(int i = 1;i<=n;i++){
                if(c[i].p == 2){
                    b[xb] = max(c[i].two_three,c[i].two_one);
                    xb++;
                }
            }
        }else{
            change = three - n/2;
            for(int i = 1;i<=n;i++){
                if(c[i].p == 3){
                    b[xb] = max(c[i].three_one,c[i].three_two);
                    xb++;
                }
            }
        }
        sort(b,b+xb,cmp);
        for(int i = 0;i<change;i++){
            sum += b[i];
        }
        cout << sum << endl;
    }
    return 0;
}
