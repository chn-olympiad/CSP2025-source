#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[1000010];
bool cmp(int al,int bl){
	return al>bl;
}
int main(){
	//qian dao 0eeee
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	memset(a,-1,sizeof(a));
	string s;cin>>s;
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]-48>=0&&s[i]-48<=9){
			cnt++;
			a[cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1,cmp);
	if(a[1]==-1||a[1]==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=cnt;i++){
		cout<<a[i];
	}
	return 0;
}
