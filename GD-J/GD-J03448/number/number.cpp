#include<bits/stdc++.h>
using namespace std;
long long n=1,m,k[1000001];
char s[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","W",stdout);
	cin>>s;
	for(int i=0;i<strlen(s);i++){
		if(s[i]>='0'&&s[i]<='9'){
			k[n]=int(s[i]-'0');
			n++;
		}
	}
	sort(k+1,k+n+1);
	for(int i=n;i>1;i--){
		cout<<k[i];
	}
	return 0;
}
