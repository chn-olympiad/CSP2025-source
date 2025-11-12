#include<bits/stdc++.h>
using namespace std;
long long n,m,b[1000100];
int a[1000100];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int j=0;
	for(int i=0;i<=s.size();i++){
		if(s[i]=='0'){
			a[j++]=0;
		}else if(s[i]=='1'){
			a[j++]=1;
		}else if(s[i]=='2'){
			a[j++]=2; 
		}else if(s[i]=='3'){
			a[j++]=3;
		}else if(s[i]=='4'){
			a[j++]=4;
		}else if(s[i]=='5'){
			a[j++]=5;
		}else if(s[i]=='6'){
			a[j++]=6;
		}else if(s[i]=='7'){
			a[j++]=7;
		}else if(s[i]=='8'){
			a[j++]=8;
		}else if(s[i]=='9'){
			a[j++]=9;
		}
	}
	sort(a,a+j);
	for(int i=j-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
