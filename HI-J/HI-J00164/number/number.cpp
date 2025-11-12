#include<bits/stdc++.h>
using namespace std;
int num[1100000];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int n=0;
	cin>>s;
	if(s.size()==1){
		cout<<s;
		return 0;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			n++;
			num[n]=s[i]-'0';
		}
	}
	sort(num+1,num+n+1,cmp);
	for(int i=1;i<=n;i++){
		cout<<num[i];
	}
	return 0;
}
