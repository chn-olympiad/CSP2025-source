#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define uint unsigned int
#define str string
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	int n,k,sum_x=0;
	cin>>n>>k;
	vector<int> v,vis;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		v.emplace_back(a);
	}
	int js=0;
	while(1){
		for(uint i=0;i<v.size();i++){
			int sum=0;
			for(uint j=i;j<=v.size();i++){
				for(uint a=i;a<=j;i++){
					sum^=v[a];
					if(find(vis.begin(),vis.end(),a)!=v.end()){
						break;
					}
					vis.emplace_back(a);
				}
				if(sum==k){
					sum_x++;
					js=0;
				}
			}
		}
		if(js==10){
			break;
		}
		js++;
	}
	cout<<sum_x;
	return 0;
}