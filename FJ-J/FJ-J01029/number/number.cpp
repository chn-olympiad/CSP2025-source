#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int tot;
bool cmp1(int c,int d){
	return c>d;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[++tot]=s[i]-'0';
		}
	}
	sort(a+1,a+tot+1,cmp1);
	for(int i=1;i<=tot;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
