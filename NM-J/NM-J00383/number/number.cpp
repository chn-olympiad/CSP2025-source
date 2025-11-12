#include<bits/stdc++.h>
using namespace std;
int s[1000000],a=0,i=0,n=0;
int main(){
	freopen("number.in","s[i]",stdin);
	freopen("number.out","s[i]",stdout);
	for(int i=0;i<=1000000;i++){
		if(s[i]>=0 && s[i]<=9){
			cin>>s[i];
		}
		else if(s[i+1]>s[i]){
			s[i]=a;s[i+1]=s[i];a=s[i+1];
		}
	}
	cout<<s[i];
	return 0;
}
