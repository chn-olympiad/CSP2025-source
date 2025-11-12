#include<bits/stdc++.h>
using namespace std;
char s[100010];
int a[100010];
int n=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<(int)strlen(s);i++){
		if(s[i]>='0' and s[i]<='9'){
			a[n]=s[i];
			n++;
		}
	}
	sort(a,a+n+1);
	for(int i=n;i>=1;i--){
		cout<<a[i]-48;
	}
	return 0;
}
