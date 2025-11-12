#include<bits/stdc++.h>
using namespace std;
long long i=1,t=1;
char s[1000005];
long long a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long len=strlen(s);
	for(int i=0;i<=len-1;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[t]=s[i]-48;
			t++;
		}
	}
	sort(a+1,a+t+1); 
	for(int i=t;i>1;i--){
		cout<<a[i];
	}
	return 0;
}
