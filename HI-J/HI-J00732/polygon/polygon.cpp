#include<bits/stdc++.h>
#include<vector>
using namespace std;
int a[5005],t,n;
void dfs(vector <int>x,int g,int d){
	auto o=x;
	if(x.size()==g){
		int b=0;
		for(int i=0;i<x.size()-1;i++)
		{
			b+=x[i];
		}
		if(*(x.end()-1)<b){
			t++;
		} 
		return;
	}
	if(d>=n){
		return;
	}
	cout<<o.size()<<' '<<g<<endl;
	for(int i=d+1;i<o.size();i++){
		dfs(o,g,i);
	}
	o.pop_back();
	dfs(o,g,d+1);
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	vector <int>x;
	for(int i=3;i<n-1;i++)
		dfs(x,i,1);
	cout<<t;
	return 0;
}
