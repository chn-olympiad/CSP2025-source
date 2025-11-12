#include <bits/stdc++.h>
using namespace std;
string a;
int num[1000001]={0},sth=0,j;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int n=a.size();
	for(int i=0;i<=n;++i){
		if(a[i]=='0'){
			num[sth]=0;
			++sth;
		}
		if(a[i]=='1'){
			num[sth]=1;
			++sth;
		}
		if(a[i]=='2'){
			num[sth]=2;
			++sth;
		}
		if(a[i]=='3'){
			num[sth]=3;
			++sth;
		}
		if(a[i]=='4'){
			num[sth]=4;
			++sth;
		}
		if(a[i]=='5'){
			num[sth]=5;
			++sth;
		}
		if(a[i]=='6'){
			num[sth]=6;
			++sth;
		}
		if(a[i]=='7'){
			num[sth]=7;
			++sth;
		}
		if(a[i]=='8'){
			num[sth]=8;
			++sth;
		}
		if(a[i]=='9'){
			num[sth]=9;
			++sth;
		}
	}
	for(int xxx=0;xxx<sth;++xxx){
		for(int i=0;i<sth;++i){
			if(num[i]>num[i+1]){
				j=num[i];
				num[i]=num[i+1];
				num[i+1]=j;
			}
		}
	}
	for(int i=sth;i>0;--i){
		cout<<num[i];
	}
	return 0;
}
