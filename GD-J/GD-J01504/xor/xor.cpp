#include<bits/stdc++.h>
using namespace std;
int ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k1;
	cin>>n>>k1;
	
	int a[500050]={0};
	
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		a[i]=t;
	}
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int k=i;k<=n;k++){
			if(sum==0){
				sum=a[i];
				if(sum==k1){
					ans++;
					i=k;
					break;
				}
				continue;		
			}
			
			sum=int(sum^a[k]);

			if(sum==k1){

				ans++;
				i=k;
				break;
			}
			
				
		}	
	}

	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
