#include <bits/stdc++.h>
#include<cstdio>
using namespace std;
string s;
int a[1000005],k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9' && s[i]>='0') a[k++]=s[i]-'0';
	}
	sort(a,a+k);
	for(int i=k-1;i>=0;i--) cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
