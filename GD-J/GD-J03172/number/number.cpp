#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int n,a[N],cnt;


int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(0<=s[i]-'0'&&9>=s[i]-'0'){
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
