#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
string s;
int t=0,a[N]={};

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			++t;
			a[t]=s[i]-'0';
		}
	}
	sort(a+1,a+1+t);
	for(int i=t;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
