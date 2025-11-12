#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
string s;
int num[N];
int cnt;//X X Y
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	s=' '+s;
	for(int i=1;i<=l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[++cnt]=s[i]-'0';
		}
	}
	sort(num+1,num+cnt+1);
	for(int i=cnt;i>=1;i--){
		cout<<num[i];
	}
	return 0;
} 
