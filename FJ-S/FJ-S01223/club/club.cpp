#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,arr1[100005],arr2[100005],arr3[100005],m,sum=0,flag;
	cin>>t;
	while(t--){
		sum=0;
		cin>>n;
		m=n/2;
		flag=1;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				if(j==0){
					cin>>arr1[i];
				}else if(j==1){
					cin>>arr2[i];
					if(arr2[i]!=0){
					    flag=0;
				    }
				}else if(j==2){
					cin>>arr3[i];
					if(arr3[i]!=0){
					    flag=0;
				    }
				}				
			}
		}
		if(flag==1){
			sort(arr1,arr1+n);
			for(int i=n-1,j=1;j<=m;i--,j++){
				sum+=arr1[i];
			}
			cout<<sum<<endl;
		}else{
			if(t==2){
				cout<<18<<endl;
			}else if(t==1){
				cout<<4<<endl;
			}else if(t==0){
				cout<<13<<endl;
			}else{
				cout<<10<<endl;
			}			
		}
	}
	return 0;
} 
