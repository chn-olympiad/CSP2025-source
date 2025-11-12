#include<bits/stdc++.h>
using namespace std;
string x;
long long a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>x;
	long long i,j,n=x.length();
	for(i=0;i<n;i++){
		if(x[i]>='0'&&x[i]<='9'){
			a[x[i]-'0']++;
		}
	}
	for(i=9;i>=0;i--){
		if(a[i]>0){
			for(j=1;j<=a[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}
