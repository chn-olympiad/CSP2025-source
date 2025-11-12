#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005],b,c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	s=' '+s;
	b=s.size();
	for(int i=1;i<=b-1;i++){
		if(s[i]=='0'){
			a[i]=0;
			c++;
		}
		if(s[i]=='1'){
			a[i]=1;
			c++;
		}
		if(s[i]=='2'){
			a[i]=2;
			c++;
		}
		if(s[i]=='3'){
			a[i]=3;
			c++;
		}
		if(s[i]=='4'){
			a[i]=4;
			c++;
		}
		if(s[i]=='5'){
			a[i]=5;
			c++;
		}
		if(s[i]=='6'){
			a[i]=6;
			c++;
		}
		if(s[i]=='7'){
			a[i]=7;
			c++;
		}
		if(s[i]=='8'){
			a[i]=8;
			c++;
		}
		if(s[i]=='9'){
			a[i]=9;
			c++;
		}
	}
	sort(a+1,a+b+1,greater<long long>());
	for(int i=1;i<=c;i++){
		cout << a[i];
	}
	return 0;
}
