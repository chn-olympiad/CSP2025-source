#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=strlen(s);
	int w=0;
	for(int i=0;i<=n-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
		 	w++;
		 }
	    if(s[i]=='1') a[w]=1;
		if(s[i]=='2') a[w]=2; 
		if(s[i]=='3') a[w]=3;
		if(s[i]=='4') a[w]=4; 
		if(s[i]=='5') a[w]=5;
		if(s[i]=='6') a[w]=6; 
		if(s[i]=='7') a[w]=7;
		if(s[i]=='8') a[w]=8; 
		if(s[i]=='9') a[w]=9;
		if(s[i]=='0') a[w]=0;
}
	sort(a+1,a+1+w);
	
	long long ans=0;
	long long q=1;
	for(int i=1;i<=w;i++){
		ans+=q*a[i];
		q*=10;
	}
	cout<<ans;
	return 0;
} 
