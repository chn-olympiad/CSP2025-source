#include <bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,max=0,flag=0,c;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		for(int j=1;j>i;j++){
			for(int k=1;k>j;k++){
				if(a[i]>max){
					max=a[i];
				}
				if((1+n)*1.0*n/2>max*2){
					flag=1;
					}
				if(flag!=0){
					c++;
				}
			}
		}
	}
	cout<<c-2;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
