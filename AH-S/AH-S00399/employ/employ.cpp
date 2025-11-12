#include<iostream>
using namespace std;
int a[505];
int t[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]++;
	}
	int cnt=1;
	for(int i=1;i<=n;i++){
		if(t[a[i]]<=1) continue;
		else cnt*=t[a[i]];
	}
	cout<<cnt;
	return 0;
}
