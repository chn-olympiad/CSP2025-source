#include<bits/stdc++.h>
using namespace std;
int n,k,a[10009]={0},num=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i]; 
	}
	bool flag=0;
	for(int i=0;i<n;i++){
		if(!(a[i]==0||a[i]==1)){
			flag=1;
			break;
		}
	}
	if(flag==0){
		if(k==0){
			bool flag=0;
			for(int i=0;i<n;i++){
				if(a[i]==0){
					flag=1;
					break;
				}
			}
			if(flag==1){
				for(int i=0;i<n-1;i++){
					if(a[i]==0){
						num++;
					}
					if(a[i]==1&&a[i+1]==1){
						num++;
						i++;
					} 
				}
				cout<<num;
			}
			else{
				cout<<int(n/2);
			}
		}
		if(k==1){
			for(int i=0;i<n;i++){
				if(a[i]==1){
					num++;
				} 
			}
			cout<<num;
		}
	}
	else{
		
	}
	return 0;
}
/*
100 1
1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1

10 0

*/
