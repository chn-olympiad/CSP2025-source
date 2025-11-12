#include<bits/stdc++.h>
using namespace std;
long long t[12];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char c;
	while(cin>>c)
		if(c>='0'&&c<='9')
			t[c-'0']++;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=t[i];j++)
			cout<<i;
	return 0;
}
