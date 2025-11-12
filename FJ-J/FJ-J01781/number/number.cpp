#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int cnt[N],ans;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt[ans+1]=s[i]-'0';
			ans++;
		}
	}
	sort(cnt+1,cnt+1+ans,cmp);
	for(int i=1;i<=ans;i++){
		cout<<cnt[i];
	}
	return 0;
}
