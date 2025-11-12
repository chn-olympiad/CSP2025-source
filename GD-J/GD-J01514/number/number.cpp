#include<bits/stdc++.h>
using namespace std;
int x[1000005];
string s;
int t;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			x[t++]=s[i]-'0';
		}
	}
	sort(x,x+t,cmp);
	for(int i=0;i<t;i++){
		cout<<x[i];
	}
	return 0;
}
