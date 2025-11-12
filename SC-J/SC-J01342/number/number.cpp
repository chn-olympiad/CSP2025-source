#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int n,ans,a[1000010],x;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("nember.out","w",stdout);
	cin>>s;
	n=int(s.size());
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			x++;
			a[x]=s[i]-'0';
		}
	}
	sort(1+a,1+a+n,cmp);
	for(int i=1;i<=x;i++) cout<<a[i];
	return 0;
}