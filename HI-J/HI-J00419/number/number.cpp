#include <bits/stdc++.h>
using namespace std;
string a;
char s[3000005];
long long b[3000005],l,cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	l=a.size();
	for(int i=0;i<=l-1;++i){
		if('0'<=a[i]&&a[i]<='9'){
			s[i]=a[i];
			cnt++;
		}
	}
	for(int i=0;i<=l-1;++i){
		if(s[i]=='0'){
			b[i]=0;
		}
		else if(s[i]=='1'){
			b[i]=1;
		}
		else if(s[i]=='2'){
			b[i]=2;
		}
		else if(s[i]=='3'){
			b[i]=3;
		}
		else if(s[i]=='4'){
			b[i]=4;
		}
		else if(s[i]=='5'){
			b[i]=5;
		}
		else if(s[i]=='6'){
			b[i]=6;
		}
		else if(s[i]=='7'){
			b[i]=7;
		}
		else if(s[i]=='8'){
			b[i]=8;
		}
		else if(s[i]=='9'){
			b[i]=9;
		}
		else b[i]=-1;
	}
	sort(b,b+l);
	for(int i=l-1;i>=0;i--){
		if(b[i]!=-1){
			cout<<b[i];
		}
	}
	return 0;
} 
