#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000500];
int sia,sib=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	sia=a.size();
	for(int i=0;i<sia;i++){
		if((int)a[i]>=48&&(int)a[i]<=57){
			b[sib]=a[i]-48;
			sib++;
		}
	}
	sort(b,b+sib);
	for(int i=sib-1;i>-1;i--){
		cout<<b[i];
	}
	return 0;
}
