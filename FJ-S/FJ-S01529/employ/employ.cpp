#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000000];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	m=n;
	cin>>s;
	int i=0;
	while(n--){
		cin>>a[i];
		i++;
	}
	cout<<pow(n,n);
	return 0;
}
