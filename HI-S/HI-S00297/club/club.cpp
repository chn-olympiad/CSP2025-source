#include<bits/stdc++.h>
using namespace std;
int a[100005][100005];
void jojo(){
	
	int n,l=0;
	cin>>n;
	l=n/2;
	for(int i=1;i<n;i++){
		for(int j=1;j<=3;j++){
			scanf("%d",&a[i][j]);
		}
	}
	long long ans=0;
	for(int k=1;k<=n;k++){
	    long long num=0,q=0;
		int aa=0,bb=0,cc=0;	
		for(int j=1;j<=n;j++){
			for(int i=1;i<=3;i++){
				int m=-1;
				if(m<a[j][i]){
					m=a[j][i];
					q=i;
				}
			}
			if(q==1){
				aa++;
			}
			else if(q==2){
				bb++;
			}
			else{
				cc++;
			}
		}	
	}
	cout<<ans<<"\n";
}
int main(){
	int t;
	cin>>t;
	while(t--){
		jojo();
	}
	return 0;
} 
