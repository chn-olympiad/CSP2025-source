#include<bits/stdc++.h>
using namespace std;
string s;int len;
const int N=1e6+10;
int num[N];int cnt;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;	
	len=s.size();
	s=' '+s;
	for(int i=1;i<=len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[++cnt]=s[i]-'0';
		}
	}
	sort(num+1,num+1+cnt);
	for(int i=cnt;i>=1;i--)
		cout<<num[i];
	return 0;
}