#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
int a[10001][100001];
int t;
cin>>t;
while(t--){
int n;
cin>>n;

for(int i=1;i<=n;i++){
for(int j=1;j<=3;j++){
cin>>a[i][j];
}
}
int c[1001];
    int maxx=INT_MIN,ans;
    for(int k=1;k<=n;k++){
    ans=0;
    for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                maxx=max(maxx,a[i][j]);
                }
                if(c[i]<2){
                    ans+=maxx;
                    c[i]++;
            }
            }
        }
        cout<<ans;
        }
return 0;
}
