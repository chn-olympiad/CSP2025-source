#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char t;
	while(cin>>t)
		if(t>='0'&&t<='9')
			a[t-'0']++;
	for(int i=9;i>=0;i--)
		while(a[i]--)
			cout<<i;
	return 0;
}
