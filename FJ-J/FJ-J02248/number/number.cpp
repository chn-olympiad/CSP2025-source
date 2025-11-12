#include<bits/stdc++.h>
using namespace std;
int a[1000001],cnt=0;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(char(s[i])>='a'&&char(s[i])<='z'||char(s[i])>='A'&&char(s[i])<='Z') continue;
		if(char(s[i])>='0'&&char(s[i])<='9'){
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+s.size(),cmp);
	for(int i=1;i<=cnt;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
