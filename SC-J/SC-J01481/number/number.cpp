#include<bits/stdc++.h>
using namespace std;
char a[1111111],b[1111111];
int main(){
	long long k=0,n;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	n=strlen(a);
	for(int i=0;i<n;i++){
		if(a[i]>='0'&&a[i]<='9'){
			k++;
			b[k]=a[i];
		}
	}
	sort(b+1,b+1+k);
	for(int i=k;i>=1;i--){
		cout<<b[i];
	}
} 