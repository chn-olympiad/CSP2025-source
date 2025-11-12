#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int cnt;
int a[N];
string s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	//rememer freopen!
	//rememer check 0!
	//8:33-8:43 expect:100pts
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+cnt+1,cmp);
	if(a[1]==0)cout<<0;
	else for(int i=1;i<=cnt;i++)cout<<a[i];
	return 0;
}
