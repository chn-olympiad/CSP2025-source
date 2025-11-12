#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int ans=0;
	int a[100001],qwq=0,m=1;
	string s;
	getline(cin,s);
	int len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[qwq]=s[i]-'0';
			qwq++;
		}
	}
	for(int i=0;i<qwq;i++){
		for(int j=m;j<qwq;j++){
			if(a[i]<a[j]){
				ans=a[i];
				a[i]=a[j];
				a[j]=ans;
				ans=0;
			}
			if(j+1==qwq) m++;
		}
	}
	for(int i=0;i<qwq;i++){
		cout<<a[i];
	}
	return 0;
}