#include<bits/stdc++.h>
using namespace std;
char s[1000005];
long long a[1000005],b;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=strlen(s);
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[b]=s[i]-'0';
			b++;
		}
	}
	sort(a,a+b);
	for(int i=b-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
