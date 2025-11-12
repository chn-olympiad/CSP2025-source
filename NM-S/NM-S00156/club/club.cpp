#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct stu{
    int b[3],ma;
}a[N];
int sec(stu z){
}
int cmp(stu x,stu y){
return x.b[x.ma]>y.b[x.ma];
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
int dp[N],num[N],vis[N];
int t,n;
cin>>t;
while(t--){
    cin>>n;
    for(int i=0;i<=n;i++){
      for(int j=0;j<3;j++){
        cin>>a[i].b[j];
        if(a[i].ma>b[j].ma){
            a[i].ma=j;
        }
      }
    }
}
sort(a,a+n,cmp);
dp[0]=b[a[0].ma];

for(int i=0;i<=n;i++){
    if(num[a[i].ma]+1>n/2){
        int k=i;
        while(k--){
            if(vis[k]==a[i].ma){
                break;
            }
        }
        int x=sec(a[i]);
        int y=sec(a[k])
    }
}





	return 0;
}
