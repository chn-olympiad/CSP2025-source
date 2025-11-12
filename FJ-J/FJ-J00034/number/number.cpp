#include<bits/stdc++.h>
using namespace std;

string s;
int n,a[1000007],t;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]<='9')a[++t]=s[i]-'0';
	}
	sort(a+1,a+t+1);
	if(!t)cout<<0;
	else for(int i=t;i>0;i--)cout<<a[i];
	return 0;
} 
