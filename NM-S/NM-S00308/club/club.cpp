#include<bits/stdc++.h>
using namespace std;
const int N = 10010;
int t,a[N][N],n,x,big = -1,q,w,e,L = -1,sum,p;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<3;j++)cin >> a[i][j];
        for(int i =0;i<n;i++){
                big=-1;
            for(int j = 0;j<3;j++){
                big = max(big,a[i][j]);
                if(j==1)q++;
                if(j==2)w++;
                if(j==3)e++;
                p = big;
                if(p<big)p = big;
			}
			sum+=p;
        }
        }
    cout << sum;
    return 0;
}




