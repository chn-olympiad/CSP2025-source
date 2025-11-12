#include<bits./stdc++.h>
using namespace std;
string a;
long long b[100000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	long long lp=0;
	for(long long i=0;i<=a.size()-1;i++){
		if(a[i]==' ') break;
		if(a[i]=='1'){
			b[lp]=1;
			lp++;
		}
		if(a[i]=='2'){
			b[lp]=2;
			lp++;
		}
		if(a[i]=='3'){
			b[lp]=3;
			lp++;
		}
		if(a[i]=='4'){
			b[lp]=4;
			lp++;
		}
		if(a[i]=='5'){
			b[lp]=5;
			lp++;
		}
		if(a[i]=='6'){
			b[lp]=6;
			lp++;
		}
		if(a[i]=='7'){
			b[lp]=7;
			lp++;
		}
		if(a[i]=='8'){
			b[lp]=8;
			lp++;
		}
		if(a[i]=='9'){
			b[lp]=9;
			lp++;
		}
		if(a[i]=='0'){
			b[lp]=0;
			lp++;
		}
	}
	long long o=0;
	for(long long i=0;i<=lp;i++){
		for(long long i=1;i<=lp;i++){
			if(b[i]>b[i-1]){
				o=b[i-1];
				b[i-1]=b[i];
				b[i]=o;
			}
		}
	}
	
	for(long long i=0;i<=lp-1;i++){
		cout<<b[i];
	}
	return 0;
}
//999第一题生吃1个小时
//香火999 
