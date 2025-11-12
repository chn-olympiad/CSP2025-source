#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000001];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	int len=s.size()-1;
	int cnt=0,tmp=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt]=s[i]-'0';
			tmp++;
			cnt++;
		}
		else continue;
	}
	sort(a+1,a+tmp+1,cmp);
	for(int i=0;i<tmp;i++)cout<<a[i];
	return 0;
}
