#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,a[N];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;
	for(char c:s)if(isdigit(c))
		a[++n]=c-'0';
	sort(a+1,a+1+n,greater<int>());
	for(int i=1;i<=n;++i)
		cout<<a[i];
	return 0;
}