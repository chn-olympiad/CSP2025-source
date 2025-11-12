#include <bits/stdc++.h>
using namespace std;
int n,m,a[501],fl=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
	cin>>a[i];
	if(s[i]=='0') fl=0;
	}
	if(n==m)
	{
		for(int i=0;i<n;i++){
			if(s[i]=='0')
			{
				cout<<0;
				return 0;
			}
		}cout<<1;
		return 0;
	}else if(fl){
		sort(a+1,a+n+1);
		cout<<0;
	}
	return 0;
}

