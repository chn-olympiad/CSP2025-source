#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int b[N],k=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>=48&&a[i]<=57){
			b[k]=a[i]-48;
			k++;			
		}
	}
	sort(b,b+k);
	for(int i=k-1;i>=1;i--){
		cout<<b[i];
	}
	return 0;
}



