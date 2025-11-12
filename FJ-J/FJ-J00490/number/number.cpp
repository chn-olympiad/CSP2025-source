#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[1000005],b=1,c,i=1;
	while(cin>>b){
		if(b-'a'==0){
			a[i]=b;
			i++;
		}
	}
	for(int j=1;j<=i;j++){
		for(int k=1;k<=i;k++){
			if(a[k]>a[k-1]){
				c=a[k];
				a[k]=a[k+1];
				a[k+1]=c;
			}
		}
	}
	for(int j=1;j<=i;j++){
		cout<<a[j];
	}
	return 0;
}
