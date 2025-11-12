#include<bits/stdc++.h>
using namespace std;
string s;
int i=1,l=0;
long long a[1000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=s.size();i>=1;i--){
		if(s[i]=='1'){a[i]+=1;l++;}
		if(s[i]=='2'){a[i]+=2;l++;}
		if(s[i]=='3'){a[i]+=3;l++;}
		if(s[i]=='4'){a[i]+=4;l++;}
		if(s[i]=='5'){a[i]+=5;l++;}
		if(s[i]=='6'){a[i]+=6;l++;}
		if(s[i]=='7'){a[i]+=7;l++;}
		if(s[i]=='8'){a[i]+=8;l++;}
		if(s[i]=='9'){a[i]+=9;l++;}
	}
	sort(a+1,a+l+1);
	for(long long i=l;i>=1;i--){
	cout<<a[i];
	}
	return 0;
}
