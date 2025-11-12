#include<bits/stdc++.h>
#include<string>
using namespace std;
string s,s1;
int a[114514],xb=1,xa;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=int(s.size());i++){
		if((s[i]=='1')||(s[i]=='2')||(s[i]=='3')||(s[i]=='4')||(s[i]=='5')||(s[i]=='6')||(s[i]=='7')||(s[i]=='8')||(s[i]=='9')||(s[i]=='0')){
		a[xb]=int(s[i]-'0');
		xb+=1;
		}
		
	}
	xa=xb-1;
	sort(a+1,a+xa+1,cmp);
	for(int i=1;i<=xa;i++){
		
		cout<<a[i];
	}
	
	return 0;
}
