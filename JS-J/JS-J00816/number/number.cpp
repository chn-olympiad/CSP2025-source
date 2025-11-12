#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int t=0,f[114514];
	for(int i=0;i<=114514;i++){
		if(s[i]=='\0')break;
		if(s[i]>='0'&&s[i]<='9'){
			f[t]=s[i]-'0';
			t++;
		}
	}
	sort(f,f+t-1,cmp);
	for(int i=0;i<t;i++){
		cout<<f[i];
	}
}
