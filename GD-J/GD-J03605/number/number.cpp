#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			a[i]=0;
		}else if(s[i]=='1'){
			a[i]=1;
		}else if(s[i]=='2'){
			a[i]=2;
		}else if(s[i]=='3'){
			a[i]=3;
		}else if(s[i]=='4'){
			a[i]=4;
		}else if(s[i]=='5'){
			a[i]=5;
		}else if(s[i]=='6'){
			a[i]=6;
		}else if(s[i]=='7'){
			a[i]=7;
		}else if(s[i]=='8'){
			a[i]=8;
		}else if(s[i]=='9'){
			a[i]=9;
		}else a[i]=-1;
	}
	sort(a,a+s.size());
	for(int i=s.size()-1;i>=0;i--){
		if(a[i]!=-1){
			printf("%lld",a[i]);
		}
	}
	return 0;
} 
