#include "bits/stdc++.h"
using namespace std;
int a[1000005];
bool cmp(int p1,int p2){
	return p1>p2;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	int n=s.size(),ans=0;
	for (int i=0;i<n;i++){
		if (s[i]>='0'&&s[i]<='9'){
			ans++;
			a[ans]=s[i]-'0';
		}
	}
	sort(a+1,a+ans+1,cmp);
	for (int i=1;i<=ans;i++)cout<<a[i];
	return 0;
}
