#include<bits/stdc++.h>
using namespace std;
string s;
int a[100005];
char c[100005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int index=1;
	for(int i=0;i<s.length();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[index++]=s[i]-'0';
		}
	}
	sort(a+1,a+1+index,cmp);
	for(int i=1;i<index;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

