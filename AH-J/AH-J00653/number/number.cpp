#include<bits/stdc++.h>
using namespace std;
int a[10];
char s[1000005];
int main(){
	freopen("number.out","w",stdout);
	freopen("number.in","r",stdin);
	cin>>s;
	for(int i=0;s[i]!=s[1000003];i++) if(s[i]>='0'&&s[i]<='9') a[s[i]-48]++;
	for(int i=9;i>=0;i--){
		while(a[i]!=0){
			cout<<i;
			a[i]--;
		}
	}
	return 0;
}
