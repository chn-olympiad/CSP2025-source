#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int num[50005];
	for(int i=1;i<=n;i++) cin>>num[i];
	int sum=0;
	if(n<=2&&k==0){
		cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(num[i]==0){
				sum++;
			}
		}
		cout<<sum;
		fclose(stdin);
		fclose(stdout);
		return 0;		
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(num[i]==1){
				sum++;
			}
		}
		cout<<sum;
		fclose(stdin);
		fclose(stdout);
		return 0;	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
