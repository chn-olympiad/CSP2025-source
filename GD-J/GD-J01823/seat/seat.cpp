#include<bits/stdc++.h>
using namespace std;
long long a[5000005],b[5000005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,y,ans;
	cin>>n>>y>>ans;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
		
	}
	for(int i=1;i<=n;++i){for(int j=0;j<=n-i;++j){if((b[i+j]^b[i-1])==y){
				cout<<i<<' '<<i+j<<"\n";
				i=i+j;					
				ans++;
				break;
			}
			
		}
		
	
		
	}
	cout<<ans;

	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
