#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,i,k;
	cin>>n>>k;
	bool a[200001];
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	int sum=0;
	for(i=0;i<n;i++){
		if(k==1){
			if(a[i]==1){
				sum++;
			}
		}else{
			if(a[i]==0){
				sum++;
			}
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}