#include<bits/stdc++.h>
using namespace std;
char s[1000000],n;
int m;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	cin>>s;
	while(s[m]!=0){
		m++;
	}
	for(int j=9;j>=0;j--){
		for(int i=0;i<m;i++){
			if(s[i]-48==j)cout<<s[i];
		}
		if(n-48==j)cout<<n;
	}
	return 0;
}
