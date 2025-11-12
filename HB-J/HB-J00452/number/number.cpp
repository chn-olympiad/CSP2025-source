#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("input.number","r",stdin);
	freopen("output.number","w",stdout);
	string a;
	cin>>a;
	int i=0,b[1000005]={0},n=a.length(),j=1;
	while(i<n){
		if(a[i]>=48&&a[i]<=57){
			b[j]=a[i]-48;
			j++;
		}i++;
	}sort(b+1,b+j);
	for(i=j-1;i>=1;i--){
		cout<<b[i];
	}return 0;
}
