#include<bits/stdc++.h>
using namespace std;
string a[100];
string s,sum;
int n=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')
			a[int(s[i]-'0')]+=s[i];
	}
	for(int i=9;i>=0;i--)
		sum=sum+a[i];
	cout<<sum;
	return 0;
}
