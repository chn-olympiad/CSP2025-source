#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000020];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	int j=1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=(s[i]-'0');
			j++;
		}
	}
	sort(a+1,a+1+j,greater<int>());
	if(a[1]==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=j;i++)cout<<a[i];
	return 0;
} 