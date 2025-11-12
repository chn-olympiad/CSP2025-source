#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll T,n,x,y,z,s[100005],s1[100005],s2[100005];
void sol(){
	cin>>n;
	ll sum=0,a=0,b=0,c=0,cnt=0,c1=0,c2=0;
	for(int i=1;i<=n;i++){
		cin>>x>>y>>z;
		ll mx=max(x,max(y,z));
		sum+=mx;
		if(mx==x) s[++cnt]=min(x-y,x-z),a++;
		else if(mx==y) s1[++c1]=min(y-x,y-z),b++;
		else s2[++c2]=min(z-x,z-y),c++;
	}
	ll mx=max(a,max(b,c));
	if(mx<=n/2){
		cout<<sum<<"\n";
		return;
	}
	if(mx==b){
		cnt=0;for(int i=1;i<=c1;i++) s[++cnt]=s1[i];
	}else if(mx==c){
		cnt=0;for(int i=1;i<=c2;i++) s[++cnt]=s2[i];
	}
	mx-=n/2;
	sort(s+1,s+cnt+1);
	for(int i=1;i<=mx;i++) sum-=s[i];
	cout<<sum<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--) sol();
	return 0;
} 
