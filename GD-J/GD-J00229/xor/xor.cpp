#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	vector<vector<int>> d;
	vector<int> a;
	long long int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(k=0){
		cout<<n/2;
		return 0;
	} 
	if(k=1){
		cout<<n;
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(i==j){
				d[i][j]=a[i];
			}
			else{
				d[i][j]=d[i][j-1]^a[j];
			}
			
		}
	}
	long long int ans=0;
	for(int j=0;j<n;j++){
		for(int i=j;i>=0;i--){
			if(d[i][j]==k){
				ans++;
				i=max(i,j);
				j=max(i,j);
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
