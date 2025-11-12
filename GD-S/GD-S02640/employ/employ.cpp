#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m,a[N];
long long res=0;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	getline(cin,s);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]>=i){
			res+=i;
		}
	}
	cout<<res;
	return 0;
}
