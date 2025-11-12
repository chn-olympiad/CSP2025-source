#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a,b[1000];
	cin>>a;
	int i=0;
	while(a!=0){
		b[i]=a%10;
		a/=10;
		i++;
	}
	for(int j=0;j<i;j++){
		for(int k=0;k<i;k++){
			if(b[j]>b[k]){
				swap(b[j],b[k]);
			}
		}
	}
	for(int j=0;j<i;j++){
		cout<<b[j];
	}
	return 0;
} 