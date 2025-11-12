#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],tot;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i = 0; i < int(s.length()); i++){
		if(isdigit(s[i]))a[++tot]=s[i]-'0';
	}
	sort(a+1,a+tot+1,cmp);
	for(int i=1;i<=tot;i++)cout<<a[i];
	cout<<endl;
	
	return 0;
}
