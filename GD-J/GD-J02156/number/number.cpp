#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int x=0;
	for(int i=0;i<=1000005;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[x]=s[i]-'0';
			x++;
		}
	}
	sort(a,a+x);
	for(int i=x-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
