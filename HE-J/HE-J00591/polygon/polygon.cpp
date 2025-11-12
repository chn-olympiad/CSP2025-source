#include<bits/stdc++.h>
using namespace std;
int n1[5005];
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	int n,max=0,sum=0,sum1=0,a=0;
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >> n1[i];
	}
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-i;j++){
			 sum1=n1[j]
			for(int z=j+1;z<=i+j+1;z++){
				if(max<n1[z]){
					max=nl[z];
				}
				sum1=sum1+n1[z];
			}
	if(sum1>max*2){
			a++;
		}
		sum1=0;
		max=0;
		}
		
	}
	cout <<a;
	return 0;
} 
