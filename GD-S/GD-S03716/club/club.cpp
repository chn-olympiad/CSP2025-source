#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int t;
int n;
int ans;
struct clubb{
	int a1;
	int a2;
	int a3;
	int m;
}c[N];
int b1[N],b2[N],b3[N];
int mm[N];
int l1,l2,l3;
void add(int p){
	int x=c[p].a1;
	int y=c[p].a2;
	int z=c[p].a3;
	if(x>y&&x>z){
		b1[++l1]=p;
		c[p].m=min((x-y),(x-z));
	}
	else if(y>x&&y>z){
		b2[++l2]=p;
		c[p].m=min((y-x),(y-z));
	}
	else if(z>x&&z>y){
		b3[++l3]=p;
		c[p].m=min((z-x),(z-y));
	}
	else b1[++l1]=p;
	ans+=max(x,max(y,z));
}
void gwk(int b[],int len){
	for(int i=1;i<=len;i++){
		mm[i]=c[b[i]].m;
	}
	sort(mm+1,mm+len+1);
	for(int i=1;i<=len-n/2;i++){
		ans-=mm[i];
	}
}
void init(){
	for(int i=1;i<=n;i++){
		c[i].a1=0;
		c[i].a2=0;
		c[i].a3=0;
		c[i].m=0;
		mm[i]=0;
	}
	for(int i=1;i<=l1;i++)b1[i]=0;
	for(int i=1;i<=l2;i++)b2[i]=0;
	for(int i=1;i<=l3;i++)b3[i]=0;
	l1=l2=l3=ans=0;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			c[i].a1=x;
			c[i].a2=y;
			c[i].a3=z;
			add(i);
		}
		if(l1<=n/2&&l2<=n/2&&l3<=n/2){
			cout<<ans<<"\n";
			init();
			continue;
		}
		if(l1>n/2)gwk(b1,l1);
		else if(l2>n/2)gwk(b2,l2);
		else if(l3>n/2)gwk(b3,l3);
		cout<<ans<<"\n";
		init();
	}
	return 0;
}
