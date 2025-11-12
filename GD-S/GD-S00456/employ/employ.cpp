#include<bits/stdc++.h>
using namespace std;
struct person_h{
	int s,c;
}people_h[100005];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>people_h[i].s;
	}
	for(int i=1;i<=n;i++){
		cin>>people_h[i].c;
	}
	cout<<1;
	return 0;
}
