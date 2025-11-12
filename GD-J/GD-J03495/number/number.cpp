#include<bits/stdc++.h>
using namespace std;
const int Nn=1e6+10;
string a;
long long Qw[Nn];
long long Oo=0,Kk=0,Aa=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	Kk=a.length();
	for(long long i=0;i<Kk;i++){
		if(a[i]>='0' && a[i]<='9'){
			Qw[Oo]=a[i]-'0';
			Oo++;	
		}
	}
	sort(Qw,Qw+Oo);
	Oo--;
	for(long long i=Oo;i>=0;i--){
		cout<<Qw[i];
	}
	
	return 0;
} 
