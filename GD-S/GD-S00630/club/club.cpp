#include<bits/stdc++.h>
using namespace std;
int T,n,m,m1,m2,m3,c1,c2,c3;
long long s;
int b[100005];
struct node{
	long long d1,d2,d3,z;
}a[100005];
bool cmp(node x,node y){
	return x.d1>y.d1;
}
void d(int x){
	int en=n/2;
	if(x>n){
		long long ss=0;
		m1=m2=m3=0;
		for(int i=1;i<=n;i++){
			if(b[i]==1){
				m1++;
				ss+=a[i].d1;
			}
			if(b[i]==2){
				ss+=a[i].d2;
				m2++;
			}
			if(b[i]==3){
				ss+=a[i].d3;
				m3++;
			}
		}
		if(m1<=en&&m2<=en&&m3<=en){
			s=max(s,ss);
		}
		return;
	}
	for(int i=1;i<=3;i++){
		b[x]=i;
		d(x+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%d",&n);
		s=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].d1,&a[i].d2,&a[i].d3);
			a[i].z=abs(a[i].d1-a[i].d2);
			if(a[i].d1>0)c1=1;
			if(a[i].d2>0)c2=1;
			if(a[i].d3>0)c3=1;
		}
		if(c1&&!c2&&!c3){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				s+=a[i].d1;
			}
			printf("%lld\n",s);
		}
		else if(n<=10){
			s=-1;
			d(1);
			printf("%lld\n",s);
		}
	}
	return 0;
}
