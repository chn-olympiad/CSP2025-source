#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],x=0,c=0,s0=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>'0'&&s[i]<='9'){
			a[x]=s[i]-'0';
			x++;
		}else s0++;
	}
	for(int j=0;j<=s.size();j++){
		for(int i=0;i<s.size();i++){
			if(a[i]<a[i+1]){
				int t=a[i+1];
				a[i+1]=a[i];
				a[i]=t;
			}
		}
	}
	for(int i=0;i<s.size();i++){
		c=c*10+a[i];
	}
	int c0=pow(10,s0);
	if(s0==0)printf("%d",c);
	else printf("%d",c/c0);
	return 0;
}