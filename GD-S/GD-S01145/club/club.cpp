#include<bits/stdc++.h>
using namespace std;
struct RP{
	int a,b;
}t[100005];
int n,T,a[100005],b[100005],c[100005];
bool cmp(RP x,RP y){return (x.a-x.b)>(y.a-y.b);}
void swapab(){
	for(int i=1;i<=n;++i)swap(a[i],b[i]);
}
void swapac(){
	for(int i=1;i<=n;++i)swap(a[i],c[i]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		int sum=0,aa=0,bb=0,cc=0;
		for(int i=1;i<=n;++i){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>b[i]&&a[i]>c[i])aa++;
			if(b[i]>a[i]&&b[i]>c[i])bb++;
			if(c[i]>a[i]&&c[i]>b[i])cc++;
		}
		if(bb+bb>n)swapab();
		if(cc+cc>n)swapac();
		for(int i=1;i<=n;++i){
			t[i].a=a[i];
			t[i].b=max(b[i],c[i]);
		}
		sort(t+1,t+1+n,cmp);
		for(int i=1;i<=n;++i){
			if(t[i].a-t[i].b>=0&&i+i<=n)sum+=t[i].a-t[i].b;
			sum+=t[i].b;
		}
		cout<<sum<<'\n';
	}
	return 0;
}
