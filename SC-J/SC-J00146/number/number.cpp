#include<bits/stdc++.h>
using namespace std;
int const n=1e8;
long long a[n];
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long z=s.size(),j=0;
	for(long long i=0;i<z;i++){
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
	sort(a,a+j+1);
	for(long long i=j;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}