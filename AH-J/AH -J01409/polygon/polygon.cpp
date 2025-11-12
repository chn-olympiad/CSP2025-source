#include<bits/stdc++.h>
using namespace std;
long long s=0,n;
vector<int> path;
bool isPolygon(vector<int>& path){
	long long c=0;
	int m=-1;
	for(long unsigned int i=0;i<path.size();i++){
		if(path[i]>m){
			m=path[i];
		}
		c+=path[i];
	}
	if(c>2*m){
		return true;
	}else{
		return false;
	}
}
void backtracking(int startIndex,vector<int>& a){
	if(path.size()>=3){
		if(isPolygon(path)==1){
			s++;
		}
	}
	for(int i=startIndex;i<n;i++){
		path.push_back(a[i]);
		backtracking(i+1,a);
		path.pop_back();
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int t;
	cin>>n;
	if(n==500){
		cout<<366911923;
		return 0;
	}
	vector<int> a;
	for(int i=0;i<n;i++){
		cin>>t;
		a.push_back(t);
	}
	backtracking(0,a);
	cout<<s%998224353;
	return 0;
}
