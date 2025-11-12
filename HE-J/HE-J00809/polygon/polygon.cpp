#include<bits/stdc++.h>//CCF//CCF//CCF//CCF//CCF
using namespace std;//CCF//CCF//CCF//CCF//CCF//CCF
int n,a[114514];//CCF//CCF//CCF//CCF//CCF//CCF//CCF
int main() {//CCF//CCF//CCF//CCF//CCF//CCF//CCF//CCF
	freopen("polygon.in","r",stdin);//CCF//CCF//CCF
	freopen("polygon.out","w",stdout);//CCF//CCF//CCF
	ios::sync_with_stdio(0);//CCF//CCF//CCF//CCF//CCF
	cin.tie(0);//CCF//CCF//CCF//CCF//CCF//CCF//CCF
	cout.tie(0);//CCF//CCF//CCF//CCF//CCF//CCF//CCF
	cin>>n;//CCF//CCF//CCF//CCF//CCF//CCF//CCF//CCF
	int s=1;//CCF//CCF//CCF//CCF//CCF//CCF//CCF//CCF
	for(int i=1; i<=n; ++i) {//CCF//CCF//CCF//CCF//CCF
		cin>>a[i];//CCF//CCF//CCF//CCF//CCF//CCF//CCF
		s=s*a[i];//CCF//CCF//CCF//CCF//CCF//CCF//CCF
	}//CCF//CCF//CCF//CCF//CCF//CCF//CCF//CCF//CCF
	cout<<s%998244353;//CCF//CCF//CCF//CCF//CCF//CCF
	return 0;//CCF//CCF//CCF//CCF//CCF//CCF//CCF//CCF
}//CCF//CCF//CCF//CCF//CCF//CCF//CCF//CCF//CCF//CCF
/*//CCF//CCF//CCF//CCF//CCF//CCF//CCF//CCF//CCF//CCF
//CCF//CCF//CCF//CCF//CCF//CCF//CCF//CCF//CCF//CCF
*///CCF//CCF//CCF//CCF//CCF//CCF//CCF//CCF//CCF//CCF
