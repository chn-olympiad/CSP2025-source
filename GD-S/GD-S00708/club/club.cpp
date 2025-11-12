#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n;
ll ans;
int s[N];
struct node{
	int a,b,c;
};
vector<node> e;
int fma(int x){
	if(e[x].a<e[x].b){
		if(e[x].b<e[x].c)return 3;
		else if(e[x].a<e[x].c)return 2;
		else return 2;
	}
	else{
		if(e[x].b>e[x].c)return 1;
		else if(e[x].c<e[x].a)return 1;
		else return 3;
	}
}
bool cmp(node a,node b){
	return a.a>b.a;
}
bool cmp2(node a,node b){
	return a.b>b.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1,x,y,z;i<=n;i++){
			scanf("%d%d%d",&x,&y,&z);
			e.push_back({x,y,z});
			s[i]=x+y+z;
		}
		if(n==2){
			int x=fma(1),y=fma(2);
			int ma1=max({e[0].a,e[0].b,e[0].c});
			int ma2=max({e[1].a,e[1].b,e[1].c});
			int mi1=min({e[0].a,e[0].b,e[0].c});
			int mi2=min({e[1].a,e[1].b,e[1].c});
			if(x!=y){
				cout<<ma1+ma2<<endl;
				continue;
			}
			else {
				if(s[1]-ma1-mi1>s[2]-mi2-ma2){
					cout<<ma2+s[1]-ma1-mi1<<endl;
					continue;
				}
				else {
					cout<<ma1+s[2]-ma2-mi2<<endl;
					continue;
				}
			}
		}
		else{
			sort(e.begin(),e.end(),cmp);
			if(e[0].a!=0){
				for(int i=1;i<=(n>>1);i++)ans+=e[0].a,e.erase(e.begin());
				sort(e.begin(),e.end(),cmp2);
				for(int i=1;i<(n>>1);i++)ans+=e[0].b,e.erase(e.begin());
			}
			else{
				sort(e.begin(),e.end(),cmp2);
				for(int i=1;i<=(n>>1);i++)ans+=e[0].b,e.erase(e.begin());
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
