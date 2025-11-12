#include <bits/stdc++.h>
using namespace std;
string s;
long long temp=0,a[1000005],x,maxn=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(int(s[i])>=48&&int(s[i])<=57){
			a[temp]=int(s[i])-48;
			temp++;
		}
	}
	do{
		x=0;
		for(int i=0;i<temp;i++){
			x=x*10+a[i];
		}
		if(x>maxn) maxn=x;
	}while(next_permutation(a,a+temp));
	cout<<maxn;
	return 0;
}
