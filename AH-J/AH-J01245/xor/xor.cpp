#include<bits/stdc++.h>
using namespace std;
struct node{
	int x;
	int y;
};
vector<node> v;
bool cmp(node x,node y){
	if(x.y==y.y){
		return x.x<y.x;
	}
	return x.y<y.y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a[500001];
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int sum=a[i];
		if(sum==k){
			node aya;
			aya.x=i;
			aya.y=i;
			v.push_back(aya);
		}
		for(int j=i+1;j<=n;j++){
			sum^=a[j];
			if(sum==k){
				node aya;
				aya.x=i;
				aya.y=j;
				v.push_back(aya);
			}
		}
	}
	int sum=0;
	int mw=0;
	sort(v.begin(),v.end(),cmp);
	while(v.size()){
		if(v[0].x>mw){
			sum++;
			mw=v[0].y;
		}
		v.erase(v.begin());
	}
	cout<<sum;
	return 0;
}
