#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t,n,k=0;
	cin>>t;
	long long s[3]={0};
	
	while(t--){
		
		cin>>n;
		long long m[n][3];
		for(long long i=0;i<n;i++){
			for(int j=0;j<3;j++)
				cin>>m[i][j];
		}
		
		long long a;
		for(long long i=0;i<n;i++){
			a=0;
			for(int j=0;j<3;j++)
				a=max(a,m[i][j]);
			k+=a;
			for(long long j=0;j<n;j++)
				if(a==m[i][j])s[j]++;
		}
		
		cout<<k<<endl;
		k=0;
	}
	return 0;
}
