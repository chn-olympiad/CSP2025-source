#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(a,0,sizeof(a));
	string s;
	cin>>s;
	int ap=1,si=s.length();
	for(int rp=0;rp<si;rp++){
		if(s[rp]>='0'&&s[rp]<='9'){
			a[ap]=s[rp]-'0';
			ap++;
		}
	}sort(a+1,a+ap,greater<int>());
	for(int rp=1;rp<=ap-1;rp++)cout<<a[rp];
	return 0;
}