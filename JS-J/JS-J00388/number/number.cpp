#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.length();
	int x=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9')a[++x]=s[i]-'0';
	}
	sort(a+1,a+x+1,cmp);
	for(int i=1;i<=x;i++)cout<<a[i];
	return 0;
}
