#include <bits/stdc++.h>
using namespace std;
int f[5005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++){
			
			int a,b,c;
			cin>>a>>b>>c;
			for(int j=n/2;j>=1;j--){
				f[j]=max(f[j-1]+a,max(f[j]+b,f[j]+c));
				
			}
		}
		cout<<f[n/2]<<endl;
	}
	return 0;
} 
