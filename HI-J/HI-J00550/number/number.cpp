#include<bits/stdc++.h>
using namespace std;
long long a[1000001]={},b=1;
string x;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> x;
	for(int i=0 ; i <=x.size() ; i++){
		if(x[i]>='0' && x[i]<='9'){
			a[b]=x[i]-48 ;
			b++;
		}
	}
	sort(a,a+b);
	for(int j=b-1 ; j>=1 ; j--){
		cout << a[j];
	}
	return 0;
} 
