#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int n,q;string st1[200005],st2[200005],tt1,tt2;
int solve(string x,string y,int i){
	int start = x.find(st1[i]);
	if (start>=0){
		for (int j=0;j<st2[i].size();j++){
			x[start+j]=st2[i][j];
		}
		for (int j=0;j<x.size();j++){
			if (x[j]!=y[j]) return 0;
		}
		return 1;
	}
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++) cin>>st1[i]>>st2[i];
	for (int i=1;i<=q;i++){
		int cnt=0;
		cin>>tt1>>tt2;
		for (int j=1;j<=n;j++){
			cnt+=solve(tt1,tt2,j);
		}
		cout<<cnt<<endl;
	}
	return 0;
} 
