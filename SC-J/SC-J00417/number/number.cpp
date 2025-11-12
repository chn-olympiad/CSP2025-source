#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int> 
using namespace std;
int a[1000005],k=0;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	int len=s.size();
	s=' '+s;
	for(int i=1;i<=len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++k]=s[i]-'0';
		}
	}
	sort(a+1,a+k+1);
	for(int i=k;i>=1;i--)cout<<a[i];
	return 0;
}