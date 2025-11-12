#include <bits/stdc++.h>
using namespace std;
int sum(int n){
	if(n==2) return 2;
	else return n*sum(n-1);
}
char c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int cnt=0;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	sort(c,c+n);
	for(int i=0;i<n;i++){
		if(s[i]=='1') cnt++;
	}
	if(cnt==n){
		cout<<sum(n);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
