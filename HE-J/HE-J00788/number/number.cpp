#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000010],c=0,x=0,t=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0';
			c++;
		}
		if(s[i]=='0') t++;
	}
	sort(a,a+c+1,cmp);
	for(int i=0;i<c;i++){
		x=x*10+a[i];
	}
	cout<<x;
	return 0;
} 
