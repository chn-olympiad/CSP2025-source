#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int cnt=1;
	for(auto c:s)
		if(c>='0'&&c<='9'){a[cnt]=c-'0';cnt++;}
	sort(a,a+cnt);
	for(int i=cnt-1;i>=1;i--)cout<<a[i];
	cout<<endl;
	return 0;
}
