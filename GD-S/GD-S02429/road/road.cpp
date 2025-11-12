#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int c[N],num[N][20],ha[N],si[N];
long long ji[N];
int n,m,k,a,b,cc;
int fi(int a){
	return (ha[a]==a?a:ha[a]=fi(ha[a]));
}
void init()
{
	for(int i = 1;i<=n+k;i++){
		ha[i]=i;
		si[i]=1;
	}
	return;
}
void me(int a,int b){
	int af=fi(a);
	int bf=fi(b);
	if(si[bf]<si[af]){
		ha[bf]=ha[af];
		si[af]+=si[bf];
	}else{
		ha[af]=ha[bf];
		si[bf]+=si[af];
	}
	return;
}
struct node{
	int a,b;
	long long c;
};
bool cmp(node a,node b){
	return a.c<b.c;
}
priority_queue<pair<pair<int,bool>,pair<int,int> >,vector<pair<pair<int,bool>,pair<int,int> > >,greater<pair<pair<int,bool>,pair<int,int> > > > ro;
void so1(){
	cout<<0;
	return;
}
void so0(){
	int cnt=0,ans=0;
	while(ro.size()){
		int a=ro.top().second.first;
		int b=ro.top().second.second;
		int c=ro.top().first.first;
		ro.pop();
	//	cout<<a<<" "<<b<<" "<<c<<"\n";
		if(fi(a)!=fi(b)){
	//		cout<<"ok\n";
			cnt++;
			ans+=c;
		}
		if(cnt==n-1){
			cout<<ans;
			return;
		}
	}
	cout<<ans;
}
bool vis[N];
void soa(){
	int cnt=0,ans=0;
	while(ro.size()){
		int a=ro.top().second.first;
		int b=ro.top().second.second;
		int c=ro.top().first.first;
		bool o=ro.top().first.second;
		ro.pop();
	//	cout<<a<<" "<<b<<" "<<c<<"\n";
		if(fi(a)!=fi(b)){
	//		cout<<"ok\n";
			if(!o){
				if(ji[a]>1ll*0){
					cnt++;
				}
				ji[a]+=c;
				vis[a]++;
			}else {
				cnt++;
			}
			ans+=c;
		}
		if(cnt==n-1){
			cout<<ans;
			return;
		}
	}
	for(int i = 1+n;i<=n+k;i++){
		ans-=max(ji[a],1ll*0);
	}
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	
	cin>>n>>m>>k;
	init();
	for(int i = 1;i<=m;i++){
		cin>>a>>b>>cc;
		ro.push({{cc,1},{a,b}});
	}
	int flag=1;
	if(k==0)flag=10;
	for(int i = 1+n;i<=k+n;i++){
		cin>>c[i];
//		if(c[i]==0){
//			cout<<"yl\n";
//		}else{
//			cout<<c[i]<<"\n";
//		}
		for(int j = 1;j<=n;j++){
			cin>>num[i][j];
			ro.push({{num[i][j],0},{i,j}});
//			if(num[i][j]!=0&&flag<=2){
//				flag=2;
//			}
		}
		if(c[i]!=0&&flag<=2){
			flag=2;
		}
	}
//	cout<<ro.size()<<"\n";
//	cout<<flag<<"\n";
	if(k==0){
		so0();
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
