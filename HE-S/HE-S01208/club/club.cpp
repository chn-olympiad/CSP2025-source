#include<bits/stdc++.h>
using namespace std;
int n,s,ss,sss,T,ans;
struct tongxue{
	int id,y,z;
	bool f;
}a[100010],b[100010],c[100010];
bool cmp(tongxue x,tongxue y){
	return x.z>y.z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		ans=0;s=0,ss=0,sss=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].y>>b[i].y>>c[i].y;
			a[i].id=i;b[i].id=i;c[i].id=i;
			a[i].z=a[i].y-b[i].y-c[i].y;
			b[i].z=b[i].y-a[i].y-c[i].y;
			c[i].z=c[i].y-b[i].y-a[i].y;
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(a[s].z>=b[ss].z&&a[s].z>c[sss].z) ans+=a[s].y,s++;
			else if(b[ss].z>=a[s].z&&b[ss].z>c[sss].z) ans+=b[ss].y,ss++;
			else if(c[sss].z>=a[s].z&&c[sss].z>b[ss].z) ans+=c[sss].y,sss++;
		}
		cout<<ans;
	}
	return 0;
}

