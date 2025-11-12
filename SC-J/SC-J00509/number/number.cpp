#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;

int main(){
	string s;
	cin>>s;
	int n=s.size();
	int t=n+10;
	int a[t],cnt=1;
	for(int i=0;i<s.size();i++){
		if(('0'<=s[i])&&(s[i]<='9')){
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt-1;i>=1;i--) cout<<a[i];
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdin);
	return 0;
} 