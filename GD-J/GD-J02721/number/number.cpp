#include<bits/stdc++.h>
using namespace std;
int cnt,num[1000005];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			num[++cnt]=(int)(s[i]-'0');
		}
	}
	sort(num+1,num+cnt+1);
	for(int i=cnt;i>=1;i--){
		cout<<num[i];
	}
	return 0;
}
