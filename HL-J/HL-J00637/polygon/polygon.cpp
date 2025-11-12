#include<bits/stdc++.h>
using namespace std;
int l[5005];
int n;
int sum=0;
int t,x;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			
		
			if(l[i]>l[j] && l[i]>l[j+1]){
				if(l[i]+l[j]+l[j+1]>l[i]*2){
					sum+=1;
				}
			}
			if(l[i]<l[j] && l[j]>l[j+1]){
				if(l[i]+l[j]+l[j+1]>l[j]*2){
					sum+=1;
				}
			}
			if(l[j+1]>l[j] && l[i]<l[j+1]){
				if(l[i]+l[j]+l[j+1]>l[j+1]*2){
					sum+=1;
				}
			}
		}	
	}
	cout<<sum%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
