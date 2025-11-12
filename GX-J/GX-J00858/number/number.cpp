#include<bits/stdc++.h>
using namespace std;
#define ll long long;
int a[1000005]={0};
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int t=0;
	int len=s.size();
	for(int i=0;i<len;++i){
		if(s[i]<='9'&&s[i]>='0'){
				t++;
				a[t]=int(s[i]-'0');
		}
	}
	sort(a+1,a+1+t,cmp);
	if(a[1]==0) cout<<0;
	else{
		for(int i=1;i<=t;++i){
			cout<<a[i];
		}
	}
	return 0;
}
