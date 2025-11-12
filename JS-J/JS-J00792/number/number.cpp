#include<bits/stdc++.h>
using namespace std;
string s;
int num[1000005],cnt;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[++cnt]=s[i]-'0';
		}
	}
	sort(num+1,num+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<num[i];
	}
	return 0;
}
