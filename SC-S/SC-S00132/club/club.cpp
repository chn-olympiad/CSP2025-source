#include<bits/stdc++.h>
using namespace std;
int n;
struct S{
	int a,b,c;
	int Max;
}hn[100005];
int t;
bool cmp(S a,S b){
	return a.Max>b.Max;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ans=0;
		scanf("%d",&n);
		int x1=n/2,x2=n/2,x3=n/2;
		int x=1,y=1,z=1;
		for(int i=1;i<=n;i++){
			cin>>hn[i].a>>hn[i].b>>hn[i].c;
			hn[i].Max=max(hn[i].a,max(hn[i].b,hn[i].c));
		}
		sort(hn+1,hn+n+1,cmp);
		for(int i=1;i<=n;i++){
			int Maxx=hn[i].Max;
			if(Maxx==hn[i].a&&x1!=0)x1--,ans+=Maxx;
			if(Maxx==hn[i].b&&x2!=0)x2--,ans+=Maxx;
			if(Maxx==hn[i].c&&x3!=0)x3--,ans+=Maxx;
			
		}
		cout<<ans<<'\n';		
	}

	return 0;
}