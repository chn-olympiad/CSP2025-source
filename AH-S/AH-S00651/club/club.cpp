#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[100005],b[100005],c[100005];
struct node1{
	int a,b,c;
	int v(){
		return min(a-b,a-c);
	}
	friend bool operator<(node1 x,node1 y){
		return x.v()<y.v();
	}
}d1[100005];
struct node2{
	int a,b,c;
	int v(){
		return min(b-a,b-c);
	}
	friend bool operator<(node2 x,node2 y){
		return x.v()<y.v();
	}
}d2[100005];
struct node3{
	int a,b,c;
	int v(){
		return min(c-a,c-b);
	}
	friend bool operator<(node3 x,node3 y){
		return x.v()<y.v();
	}
}d3[100005];
int cnt1,cnt2,cnt3;
int ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;cnt1=cnt2=cnt3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>b[i]&&a[i]>c[i]) ans+=a[i],d1[++cnt1]={a[i],b[i],c[i]};
			else if(b[i]>c[i]) ans+=b[i],d2[++cnt2]={a[i],b[i],c[i]};
			else ans+=c[i],d3[++cnt3]={a[i],b[i],c[i]};
		}
		if(cnt1>n/2){
			cerr<<1;
			sort(d1+1,d1+cnt1+1);
			for(int i=1;i<=cnt1-n/2;i++){
				ans-=d1[i].v();
			}
		}else if(cnt2>n/2){
			cerr<<2;
			sort(d2+1,d2+cnt2+1);
			for(int i=1;i<=cnt2-n/2;i++){
				ans-=d2[i].v();
			}
		}else if(cnt3>n/2){
			cerr<<3;
			sort(d3+1,d3+cnt3+1);
			for(int i=1;i<=cnt3-n/2;i++){
				ans-=d3[i].v();
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
