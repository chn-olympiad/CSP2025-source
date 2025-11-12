#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,ans;
struct node{
	int a,b,c,maxx,minn,mid;
}a[N];
bool cmp(node a,node b){
	if(a.maxx!=b.maxx)return a.maxx>b.maxx;
	else return a.mid>b.mid;
}
int main(){
	freopen("club2.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].minn=min(a[i].a,min(a[i].b,a[i].c));
			a[i].maxx=max(a[i].a,max(a[i].b,a[i].c));
			a[i].mid=a[i].a+a[i].b+a[i].c-a[i].maxx-a[i].minn*2;
			a[i].maxx-=a[i].minn;
			ans+=a[i].minn;
			cout<<a[i].maxx<<" "<<a[i].mid<<"\n";
		}
		sort(a+1,a+n+1,cmp);
		int t[4]={0,0,0,0};
		for(int i=1;i<=n;i++){
			int tab=0;
			if(a[i].maxx+a[i].minn==a[i].a)tab=1;
			else if(a[i].maxx+a[i].minn==a[i].b)tab=2;
			else tab=3;
			if(t[tab]<n/2){
				t[tab]++,ans+=a[i].maxx;
			}
			else{
				if(a[i].mid+a[i].minn==a[i].a)tab=1;
				else if(a[i].mid+a[i].minn==a[i].b)tab=2;
				else tab=3;
				t[tab]++,ans+=a[i].mid;
			}
		}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}
