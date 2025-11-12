//p2:seat
//no big test
//maybe I AC = 100pts
#include<bits/stdc++.h>
using namespace std;
int a[191];
bool cmp(int x,int y){
    return x > y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    int k = n * m;
    for(int i = 0;i < k;i++){
        cin>>a[i];
    }
    int r = a[0],rrank = -1;
    sort(a,a + k,cmp);
    for(int i = 0;i < k;i++){
        if(a[i] == r){
            rrank = i;
            break;
        }
    }
    int i = 1,j = 1,cnt = 0;
    while(cnt <= k){
        if(rrank == cnt){
            cout<<i<<' '<<j<<endl;
            break;
        }
        if(i & 1){
            if(j == n){
                i++;
            }else{
                j++;
            }
        }else{
            if(j == 1){
                i++;
            }else{
                j--;
            }
        }
        cnt++;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}