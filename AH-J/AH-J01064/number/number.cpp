#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000005];
	int n[1000005];
	cin>>s;
	const size_t l=strlen(s);
	int t=0;
	for(size_t i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			n[t]=(int)s[i]-48;	
			t++;
		}
	}
	sort(n,n+t+1);
	for(size_t i=t;i>0;i--){
		cout<<n[i];
	}
	fclose(stdin);
	fclose(stdout);
}
