#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int n,b,sum;
vector<int> a,in;
map<vector<int>,bool> m;
int f(const vector<int> index,int sum){
	if(m[index]){
		return 0;
	}
	else{
		m[index]=1;
	}
	int ans=0;
	if(index.size()<3){
		return 0;
	}
	int ma=a[index[index.size()-1]];
	if(sum>ma*2){
		ans++;
	}
	for(int i=0;i<index.size();i++){
		vector<int> i2={};
		int s2=sum-a[index[i]];
		for(int j=0;j<index.size();j++){
			if(i==j){
				continue;
			}
			i2.push_back(index[j]);
		}
		ans+=f(i2,s2);
	}
	return ans%998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>b;
		in.push_back(i);
		a.push_back(b);
		sum+=b;
	}
	cout<<f(in,sum);
	return 0;
}
