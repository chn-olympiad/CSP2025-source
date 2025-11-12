#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=1e6+10;
string s;
int a[N],cnt;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			a[++cnt]=s[i]-'0';
		}
	} 
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 
//QWQ 100pts