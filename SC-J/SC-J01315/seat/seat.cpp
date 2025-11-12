#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e5+5;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> V;
	for(int i=1;i<=n*m;i++){
		int nums;
		cin>>nums;
		V.push_back(nums);
	}
	int tag=V[0];
	sort(V.begin(),V.end(),cmp);
	int tags;
	for(int i=0;i<V.size();i++){
		if(V[i]==tag) tags=i;
	}
	int x=tags/n+1,y;
	if(x&1) y=tags%n+1;
	else y=n-(tags%n);
	cout<<x<<' '<<y;
	return 0;
} 