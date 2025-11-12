#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cj;
	int a[110];
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	cj=a[0];
	int t=n*m;
	while(t--){
		for(int i=1;i<n*m;i++){
			int p=a[i];
			if(a[i]>a[i-1]){
				a[i]=a[i-1];
				a[i-1]=p;
			}
		}
	
	}
	int k=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[k]==cj){
					cout<<i<<" "<<j;
				}
				k++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(a[k]==cj){
					cout<<i<<" "<<j;
				}
				k++;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
