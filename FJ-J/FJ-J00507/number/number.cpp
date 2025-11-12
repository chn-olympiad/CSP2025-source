#include<bits/stdc++.h>
using namespace std;
long long a[1000010]={},x=0;
string s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[x]=s[i]-'0';
			x++;
		}
	}
	sort(a,a+x,cmp);
	for(int i=0;i<x;i++){
		cout<<a[i];
	}
	return 0;
}

