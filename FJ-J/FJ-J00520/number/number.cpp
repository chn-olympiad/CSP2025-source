#include<bits/stdc++.h>
using namespace std;
string ans="";
int n;
int a[1000100];
string s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[n]=s[i]-48;
			n++;
		}
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		ans+=char(a[i]+48);
	}
	cout<<ans;
	return 0;
}
