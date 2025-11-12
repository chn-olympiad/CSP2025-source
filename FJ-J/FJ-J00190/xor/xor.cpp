#include<bits/stdc++.h>
using namespace std;
using numt= long long;
using ull=unsigned long long;
numt xors(vector<numt> ve){
	if(ve.size()==1)return ve[0];
	return 
		ve[0] 
	xor 
		xors(vector<numt>(next(ve.begin(),1),ve.end()));
}
vector<long long> pre{0};
vector<long long> v{0};
numt n,k;
inline numt xorz(ull begin,ull end){
	return abs(pre[begin]-pre[end+1]);
}
struct node{
	long long begin;
	long long end;
};
int main(){
	freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
	cin>>n>>k;
	
	for(numt i=1;i<=n;i++){
		int vi;
		cin>>vi;
		v.push_back(vi);
	}
	for(numt i=1;i<=n;i++){
		pre.push_back(
		xors(
			vector<numt>(v.begin()+i,v.end())
			)
		);
	}
	ull res=0;
	for(int i=1;i<=n;i++){
		if(v[i]==k){
			res++;
		}
		else{
			for(int j=i+1;j<=n;j++){
				if(xorz(i,j)==k){
					res++;
					i=j+1;
				}
			}
		}
	}
	cout<<res;
}
