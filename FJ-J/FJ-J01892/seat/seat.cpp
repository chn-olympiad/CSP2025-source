#include<bits/stdc++.h>   
using namespace std;
int m,n,a[110],s[11][11],tmp=0,tx,h=0,ans1,ans2;
int main(){
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	tx=a[0];
	for(int i=0;i<n*m;i++){
		for(int j=0;j<n*m;j++){
			if(a[j]<=a[j+1]){
				tmp=a[j+1];
				a[j+1]=a[j];
				a[j]=tmp;
			}
		}
	}
	for(int i=0;i<m;i++){
		if(i%2==0){
			for(int j=0;j<n;j++){
				s[i][j]=a[h];
				h++;
			}	
		}else{
			for(int j=n;j>0;j--){
				s[i][j]=a[h];
				h++;
			}	
		}
	}	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(s[i][j]==tx){
				ans1=i+1;
				ans2=j+1;
				cout<<ans1<<" "<<ans2;
				break;
			}
		}
	}     
	return 0;
}
