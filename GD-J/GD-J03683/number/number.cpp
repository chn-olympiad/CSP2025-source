#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
const int N=1e6+10;
int a[N];
int cnt=0;
signed main(){
	
	freopen("numberr.in","r",stdin);
	freopen("an.out","w",stdout);
	cin>>s;
	int n=s.length();
	s=" "+s;
	for(int i=1;i<=n;i++){
		if(s[i]-'0'<=9&&s[i]-'0'>=0){
			cnt++;
			a[cnt]=s[i]-'0';
			
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 
