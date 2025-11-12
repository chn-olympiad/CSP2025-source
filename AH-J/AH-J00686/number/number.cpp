#include<bits/stdc++.h>
using namespace std;
int a[1000010],n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<(int)(s.size());i++){
		if(s[i]>='0'&&s[i]<='9') a[++n]=s[i]-'0';
	}
	sort(a+1,a+1+n,greater<int>());
	for(int i=1;i<=n;i++){
		cout<<(char)(a[i]+'0');
	}
	cout<<endl;
	return 0;
}
