#include <bits/stdc++.h>
using namespace std;
string s;
const int N=1e6+5;
int num[N],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout) ;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>s;
	int z=0;
	for(int i=0;i<(int)(s.size());i++){
		if('0'<=s[i]&&s[i]<='9') num[++cnt]=s[i]-'0';
		if(s[i]=='0') z++;
	}
	if(z==cnt){
		//È«ÊÇ0,
		cout<<0<<"\n" ;
		return 0;
	}
	sort(num+1,num+1+cnt);
	for(int i=cnt;i>=1;i--){
		cout<<num[i];
	}
	return 0;
} 
