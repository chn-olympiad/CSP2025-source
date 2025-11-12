#include<bits/stdc++.h>
#define ll long long;
using namespace std;
char s[1000005];
int a[1000005],b=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=strlen(s);
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			a[b]=1;
			b++;
		}
		if(s[i]=='2'){
			a[b]=2;
			b++;
		}
		if(s[i]=='3'){
			a[b]=3;
			b++;
		}
		if(s[i]=='4'){
			a[b]=4;
			b++;
		}
		if(s[i]=='5'){
			a[b]=5;
			b++;
		}
		if(s[i]=='6'){
			a[b]=6;
			b++;
		}
		if(s[i]=='7'){
			a[b]=7;
			b++;
		}
		if(s[i]=='8'){
			a[b]=8;
			b++;
		}
		if(s[i]=='9'){
			a[b]=9;
			b++;
		}
		if(s[i]=='0'){
			a[b]=0;
			b++;
		}
	}
	sort(a,a+b);
	if(a[b-1]==0) cout<<"0";
	else{
		for(int i=b-1;i>=0;i--) cout<<a[i];
		
	}
	return 0;
}


