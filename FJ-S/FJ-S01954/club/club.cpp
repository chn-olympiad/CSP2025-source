#include<bits/stdc++.h>
using namespace std;
int t,n,a1,a2,a3,bu[5],k,cnt,sum;
struct man{
	int d[5],b[5];
}m[100005];
struct xuan{
	int d1,d2;
}xu[100005];
bool operator<(xuan x,xuan y){
	return x.d1-x.d2>y.d1-y.d2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		sum=cnt=k=0,bu[1]=bu[2]=bu[3]=0;
		for(int i=1;i<=n;i++){
			cin>>a1>>a2>>a3;
			m[i].d[1]=a1,m[i].d[2]=a2,m[i].d[3]=a3;
			m[i].b[1]=1,m[i].b[2]=2,m[i].b[3]=3;
			if(m[i].d[2]<m[i].d[3]){
				swap(m[i].d[2],m[i].d[3]);
				swap(m[i].b[2],m[i].b[3]);
			}
			if(m[i].d[1]<m[i].d[2]){
				swap(m[i].d[1],m[i].d[2]);
				swap(m[i].b[1],m[i].b[2]);
			}
			if(m[i].d[2]<m[i].d[3]){
				swap(m[i].d[2],m[i].d[3]);
				swap(m[i].b[2],m[i].b[3]);
			}
		}
		for(int i=1;i<=n;i++)
			if(++bu[m[i].b[1]]>n/2)k=m[i].b[1];
		if(k==0){
			for(int i=1;i<=n;i++)sum+=m[i].d[1];
			cout<<sum<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++)
			if(m[i].b[1]==k){
				xu[++cnt].d1=m[i].d[1];
				xu[cnt].d2=m[i].d[2];
			}else sum+=m[i].d[1];
		sort(xu+1,xu+cnt+1);
		for(int i=1;i<=n/2;i++)sum+=xu[i].d1;
		for(int i=n/2+1;i<=cnt;i++)sum+=xu[i].d2;
		cout<<sum<<"\n";
	}
	return 0;
}
