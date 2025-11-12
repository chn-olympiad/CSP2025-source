#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000050],top;
string s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0')  a[++top]=s[i]-'0';
	}
	sort(a+1,a+top+1,cmp);
	for(int i=1;i<=top;i++){
		cout<<a[i];
	}	
	return 0;
} 
