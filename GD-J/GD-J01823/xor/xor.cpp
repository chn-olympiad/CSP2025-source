//xor
#include<bits/stdc++.h>
using namespace std;
long long a[5000005],b[5000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,y,ans=0;
	cin>>n>>y>>ans;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
		
	}
	for(int i=1;i<=n;++i){		
		for(int j=0;j<=n-i;++j){			
			if((b[i+j]^b[i-1])==y){
				cout<<i<<' '<<i+j<<"\n";
				i=i+1;					
				ans++;
				break;
			}
			
		}
		
		
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0£» 

	
}
