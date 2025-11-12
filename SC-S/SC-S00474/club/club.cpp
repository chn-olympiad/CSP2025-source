#include<bits/stdc++.h>
//#define int long long
#define ll long long
#define ls u<<1
#define rs ls|1
using namespace std;
const int N=1e5+5;
struct Node{int a,b,c,id;}p[N];
struct node{int c,a;};
bool cmp(node x,node y){return x.c>y.c;}
void sol(){
	int n,cnt1=0,cnt2=0,cnt3=0; ll ans=0; cin>>n;
	for(int i=1,a,b,c,mx;i<=n;i++){
		mx=0,cin>>a>>b>>c,mx=max(a,max(b,c));
		if(mx==a) p[i]={a,b,c,1},cnt1++;
		else if(mx==b) p[i]={a,b,c,2},cnt2++;
		else p[i]={a,b,c,3},cnt3++;
	}
	vector<node> val; val.clear();
	//cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<" ";
	if(cnt1<=n/2){
		for(int i=1;i<=n;i++)
			if(p[i].id==1) ans+=p[i].a;
	}
	if(cnt2<=n/2){
		for(int i=1;i<=n;i++)
			if(p[i].id==2) ans+=p[i].b;
	}
	if(cnt3<=n/2){
		for(int i=1;i<=n;i++)
			if(p[i].id==3) ans+=p[i].c;
	}
	if(cnt1>n/2){
		for(int i=1;i<=n;i++){
			if(p[i].id==1){
				int mx=max(p[i].b,p[i].c);
				val.push_back({p[i].a-mx,p[i].a});
				//cout<<p[i].a<<" "<<mx<<" ";
			}
		}
		sort(val.begin(),val.end(),cmp);
		for(int i=0;i<n/2;i++) ans+=val[i].a;
		for(int i=n/2;i<cnt1;i++) ans+=val[i].a-val[i].c;
	}
	if(cnt2>n/2){
		for(int i=1;i<=n;i++){
			if(p[i].id==2){
				int mx=max(p[i].a,p[i].c);
				val.push_back({p[i].b-mx,p[i].b});
			}
		}
		sort(val.begin(),val.end(),cmp);
		for(int i=0;i<n/2;i++) ans+=val[i].a;
		for(int i=n/2;i<cnt2;i++) ans+=val[i].a-val[i].c;
	}
	if(cnt3>n/2){
		for(int i=1;i<=n;i++){
			if(p[i].id==3){
				int mx=max(p[i].a,p[i].b);
				val.push_back({p[i].c-mx,p[i].c});
			}
		}
		sort(val.begin(),val.end(),cmp);
		for(int i=0;i<n/2;i++) ans+=val[i].a;
		for(int i=n/2;i<cnt3;i++) ans+=val[i].a-val[i].c;
	}
	cout<<ans<<"\n";
}
/*
1
2
10 9 8
4 0 0

*/
int main(){
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t; cin>>t; while(t--) sol(); return 0;
}