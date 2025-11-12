#include<bits/stdc++.h> 
using namespace std;
int n,m,b[1000],k;
string a;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++) if(a[i]>='0'&&a[i]<='9') b[a[i]-'0']++;
	for(int i=9;i>=0;i--) 
	for(int j=1;j<=b[i];j++) cout<<i;
	return 0;
}
