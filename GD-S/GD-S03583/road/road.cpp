#include <bits/stdc++.h>
using namespace std;
int a,b,c,ans,n[10001],ans1;
struct d{
	int a,b,c;
};
d e; 
vector<d> m;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>a>>b>>c;
	for (int i=1;i<=b;i++){
		cin>>e.a>>e.b>>e.c;
		m.push_back(e);
		ans+=e.c;
	}
	for (int i=1;i<=c;i++){
		cin>>ans1;
		for (int i=1;i<=a;i++){
			cin>>n[i];
			ans1+=min(n[i],m[i-1].c);
		}
		
	}
	cout<<min(ans,ans1);
	return 0;
} 
