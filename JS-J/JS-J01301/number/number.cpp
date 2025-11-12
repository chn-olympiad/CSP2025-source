#include<bits/stdc++.h>
using namespace std;
string s;
int a[10000004],cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1,cmp);
	if(a[1]==0){
		printf("0");
	}
	else{
		for(int i=1;i<=cnt;i++){
			printf("%d",a[i]);
		}
	}
	return 0;
}
