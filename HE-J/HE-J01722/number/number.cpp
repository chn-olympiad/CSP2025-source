#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+50;
string s;
ll cnt[N],t=0;
bool cmp(int x,int y){
	return x>y;
}
ll ans=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt[++ans]=s[i]-'0';
		}
	}
	sort(cnt+1,cnt+1+ans,cmp);
	for(int i=1;i<=ans;i++) cout<<cnt[i];
	
	return 0;
}
