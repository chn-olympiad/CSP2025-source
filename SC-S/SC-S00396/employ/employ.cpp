#include<bits/stdc++.h>
using namespace std;
bool b[1001];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[a[i]]=1;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	return 0;
}