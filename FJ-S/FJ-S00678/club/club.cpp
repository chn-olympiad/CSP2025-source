#include<bits/stdc++.h>
using namespace std;
int t[5];
struct mode{
	int a,b;
	int x,y;
}e[1000005];
struct mode1{
	int aa,bb;
}f[1000005];
bool cmp(mode1 x,mode1 y){
	return (x.aa-x.bb)<(y.aa-y.bb);
}
int main(){
	cin.tie(0)->sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int m;
	cin>>m;
	while(m--){
		t[1]=0;
		t[2]=0;
		t[3]=0;
		int n;
		cin>>n;
		int n1=n/2;
		for(int i=1;i<=n;i++){
			int a,b,c,a1,a2,a3;
			cin>>a>>b>>c;
			a1=1,a2=2,a3=3;
			if(b<c){
				swap(b,c);
				swap(a2,a3);
			}
			if(a<b){
				swap(a,b);
				swap(a1,a2);
			} 
			if(b<c){
				swap(b,c);
				swap(a2,a3);
			}
			e[i].a=a,e[i].b=b;
			e[i].x=a1,e[i].y=a2;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=e[i].a;
			t[e[i].x]++;
		}
		int flag=0;
		for(int i=1;i<=3;i++){
			if(t[i]>n1) flag=i;
		}
		if(flag==0){
			cout<<ans<<"\n";
			continue;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(e[i].x==flag){
				f[++cnt].aa=e[i].a;
				f[cnt].bb=e[i].b;
			}
		}
		sort(f+1,f+1+cnt,cmp);
		for(int i=1;i<=t[flag]-n1;i++){
			ans-=f[i].aa-f[i].bb;
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
