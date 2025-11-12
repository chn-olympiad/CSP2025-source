#include<bits/stdc++.h>
using namespace std;
long long a[5005],ans=0,n,h[5005];
bool v[5005];
void ss(long long t,long long z,long long d,long long x)
{
   if(t>=3&&z>d*2){
	   ans++;
	   }
	   if(t==n+1)return ;
for(int i=x;i<=n;i++){
	if(v[i]==0){
		v[i]=1;
	ss(t+1,z+a[i],max(d,a[i]),i+1);
	v[i]=0;
	}
  else continue; 
}
return ;
}
int main()
{
  freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i];
			}
	   ss(0,0,0,1);
		cout<<ans%998244353;		
    return 0;
}



