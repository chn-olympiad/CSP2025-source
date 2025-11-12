#include<bits/stdc++.h>
using namespace std;
int main(){
	struct node{
		int f,s,t;
	};
	const int n=1e5+5;
	node stu[n];
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int L;
	cin>>L;
	while(L--){
		int x;
		cin>>x;
		for(int i=1;i<=x;i++){
			int a,b,c;
			cin>>a>>b>>c;
			int maxx=max({a,b,c});
			int minn=min({a,b,c});
			stu[i].f=maxx;
			stu[i].s=a+b+c-maxx-minn;
			stu[i].t=minn;	
		}
		int cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=x;i++){
			
		}
	}
	return 0;
}
