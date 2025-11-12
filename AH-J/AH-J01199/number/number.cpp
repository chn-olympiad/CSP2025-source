#include<bits/stdc++.h>
using namespace std;
int s[1000009],cnt;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s1;
	cin>>s1;
	for(int i=0;i<int(s1.size());i++){
		if(s1[i]<='9'&&s1[i]>='0')cnt++,s[cnt]=s1[i]-'0';
	}
	sort(s+1,s+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)cout<<s[i];
	return 0;
}
//he yi wei
