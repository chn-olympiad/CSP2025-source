#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct jgt{
	int sz;
	char zf;
}s[1000005];
string n;
bool px(jgt x,jgt y){
	return x.sz>y.sz;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	int m=n.size();
	for(int i=0;i<m;i++){
		if(n[i]=='0' || n[i]=='1' ||n[i]=='2'||n[i]=='3'||n[i]=='4'||n[i]=='5'
		||n[i]=='6'||n[i]=='7'||n[i]=='8'||n[i]=='9'){
			s[i].zf=n[i];		
			s[i].sz=s[i].zf-'0';
		}
	}
	sort(s,s+m,px);
	for(int i=0;i<m;i++){
		if(s[i].zf=='0' || s[i].zf=='1' ||s[i].zf=='2'||s[i].zf=='3'||s[i].zf=='4'||s[i].zf=='5'
		||s[i].zf=='6'||s[i].zf=='7'||s[i].zf=='8'||s[i].zf=='9'){
			cout<<s[i].zf;	
		}
	}
	return 0;
}
