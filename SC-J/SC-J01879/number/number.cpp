#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long a[10086],k[10086];
	for(int i=0;i<10086;i++){
		cin>>a[i];
		if(a[i]>=0&&a[i]<=9){
			 k[i]=a[i];
		}
	}
	int max=0;
	for(int j=0;j<10000;j++){
		if(k[j]<k[j+1]){
			max=k[j+1];
		}
		int ji=max;
		max=k[0];
	    k[0]=ji;
		cout<<ji;
	}
	return 0;	
}