#include<bits/stdc++.h>
using namespace std;
	int b[13];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[1145142];
	cin>>a;
	int i=0;
	while(a[i]>10){
		if(a[i]>=48&&a[i]<=57){
			b[a[i]-48]++;
		}
		i++;
	}
	for(int j=9;j>=0;j--){
		while(b[j]!=0){
			cout<<j;
			b[j]--;
		}
	}
	return 0;
}
