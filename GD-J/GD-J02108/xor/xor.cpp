#include<iostream>
#include<vector>
using namespace std; 
int main(){
    freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	vector<vector<int>> m(n+1,vector<int>(n+1));
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			m[i][j]=a[i];
		    for(int l=i+1;l<=j;l++){
		    	m[i][j]=m[i][j] xor a[l];
			}
	    }
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
		    if(m[i][j]==k){
		    	sum++;i=j;
			}
	    }
	}
	cout<<sum;
	return 0;
}
