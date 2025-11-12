#include<bits/stdc++.h>
using namespace std;
int p[1000001];
string s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int t=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')p[t++]=s[i]-'0';
	}
	sort(p,p+t,cmp);
	for(int i=0;i<t;i++){
		cout<<p[i];
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
 
