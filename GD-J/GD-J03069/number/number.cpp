#include<bits/stdc++.h>
using namespace std;

int a[1000005];
string s;
int cur;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++) if(s[i]>='0'&&s[i]<='9'){
		a[++cur]=s[i]-'0';
	}
	sort(a+1,a+cur+1,cmp);
	if(a[1]) for(int i=1;i<=cur;i++) cout<<a[i];
	else cout<<0;
}
