#include<bits/stdc++.h>
using namespace std;
long long t;
int a[1000009];
char s[1000009];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=strlen(s);
	for(int i=0;i<=n;i++){
		if(s[i]=='0'){
			t++;
			a[t]=0;
		}
		else if(s[i]=='1'){
			t++;
			a[t]=1;
		}
		else if(s[i]=='2'){
			t++;
			a[t]=2;
		}
		else if(s[i]=='3'){
			t++;
			a[t]=3;
		}
		else if(s[i]=='4'){
			t++;
			a[t]=4;
		}
		else if(s[i]=='5'){
			t++;
			a[t]=5;
		}
		else if(s[i]=='6'){
			t++;
			a[t]=6;
		}
		else if(s[i]=='7'){
			t++;
			a[t]=7;
		}
		else if(s[i]=='8'){
			t++;
			a[t]=8;
		}
		else if(s[i]=='9'){
			t++;
			a[t]=9;
		}
	}
	sort(a+1,a+1+t);
	for(int i=1;i<=t;i++){
		cout<<a[t-i+1];
	}
	return 0;
} 
//#Shang4Shan3Ruo6Shui4
