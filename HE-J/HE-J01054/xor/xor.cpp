#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k,num=0;
	cin>>n>>k;
	int a[1000]; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ven,b=0;
	for(int i=1;i<=n;i++){
		ven=0;
		for(int j=i;j<=n;j++){
			ven+=a[j];
			if(j!=i && ven%(j-i)==0 && ven/(j-i)==k && i>b){
				num++;
				b=j;
				break;
			}
			if(j==i && a[j]==k && i>b){
				num++;
				b=j;
				break;
			}
				
		}
	}
	cout<<num;
	return 0;
}

