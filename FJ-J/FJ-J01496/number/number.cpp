#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long xb=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			a[xb]=0;
			xb++;
		}
		if(s[i]=='1'){
			a[xb]=1;
			xb++;
		}
		if(s[i]=='2'){
			a[xb]=2;
			xb++;
		}
		if(s[i]=='3'){
			a[xb]=3;
			xb++;
		}
		if(s[i]=='4'){
			a[xb]=4;
			xb++;
		}
		if(s[i]=='5'){
			a[xb]=5;
			xb++;
		}
		if(s[i]=='6'){
			a[xb]=6;
			xb++;
		}
		if(s[i]=='7'){
			a[xb]=7;
			xb++;
		}
		if(s[i]=='8'){
			a[xb]=8;
			xb++;
		}
		if(s[i]=='9'){
			a[xb]=9;
			xb++;
		}
	}
	sort(a,a+xb);
	for(int i=xb-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
