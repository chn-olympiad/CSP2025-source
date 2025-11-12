#include <bits/stdc++.h>
using namespace std;
int max(int a,int b,int c){
	a=max(a,b);
	a=max(a,c);
	return a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		int n;
		cin>>n;
		vector<vector<int>> vec(3,vector<int>(n));
		int sum=0;
		for(int j=0;j<n;j++){
			cin>>vec[0][j]>>vec[1][j]>>vec[2][j];
			int maxn=max(vec[0][j],vec[1][j],vec[2][j]);
			sum+=maxn;
		}
		cout<<sum<<endl;
	}
}
