#include<bits/stdc++.h>
using namespace std;
int a[1000005],n;
string s;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++n]=s[i]-'0';
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;i>0;i--)cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
