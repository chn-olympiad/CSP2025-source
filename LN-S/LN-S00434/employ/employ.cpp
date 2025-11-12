#include<bits/stdc++.h>
using namespace std;
int c[1000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	if(n==m){
		int t=n*(n+1)/2;
		t=t%998244353;
		cout << t;
		return 0;
	}
	sort(c+1,c+n+1);
	int sum=n;
	for(int i=1;i<=n;i++){
		if(i>=c[i]) sum--;
		int t=sum*(sum+1)/2;
		cout << t;
	}
	return 0;
}
