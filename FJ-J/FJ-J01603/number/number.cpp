#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int z=1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			a[z]=0;
			z++;
		}
		if(s[i]=='1'){
			a[z]=1;
			z++;
		}
		if(s[i]=='2'){
			a[z]=2;
			z++;
		}
		if(s[i]=='3'){
			a[z]=3;
			z++;
		}
		if(s[i]=='4'){
			a[z]=4;
			z++;
		}
		if(s[i]=='5'){
			a[z]=5;
			z++;
		}
		if(s[i]=='6'){
			a[z]=6;
			z++;
		}
		if(s[i]=='7'){
			a[z]=7;
			z++;
		}
		if(s[i]=='8'){
			a[z]=8;
			z++;
		}
		if(s[i]=='9'){
			a[z]=9;
			z++;
		}
	}
	sort(a+1,a+1+z,greater<int>());
	for(int i=1;i<z;i++){
		cout<<a[i];
	}
	return 0;
}
