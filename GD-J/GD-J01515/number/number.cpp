#include<bits/stdc++.h>
using namespace std;

namespace A{
	char c;
	int  m[11];
	void Solve(){
		while(cin>>c)if(c>='0'&&c<='9')m[c-'0']++;
		for(int i=9;i>=0;i--)for(int j=1;j<=m[i];j++)putchar(i+'0');
	}
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	A::Solve();
	return 0;
} 
