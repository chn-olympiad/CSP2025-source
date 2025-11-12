#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int a[1000006],top=0;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	for(int i=0;i<(int)s.size();i++){
		char c=s[i];
		if('0'<=c&&c<='9')a[++top]=c-48;
	}
	sort(a+1,a+top+1);
	for(int i=top;i>0;i--)cout<<a[i];
	return 0;
}