#include<bits/stdc++.h> 
using namespace std;
int n,k,a[500005],b[500005],ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
			a[i]=-1;
		}
	}
	for(int i=2;i<=n;i++){
		int x=1,y=i;
		for(int j=1;j<=n;j++){
			bool temp=true;
			for(int z=x;z<=y;z++){
				if (a[z]==-1){
					temp=false;
					break;
				}
			}
			if(temp){
				if((b[y]^b[x-1])==k){
					ans++;
					for(int z=x;z<=y;z++){
						a[z]=-1;
					}
					x+=i;
					y+=i;
				}
				else{
					x++;
					y++;
				}
			}
			else{
				x++;
				y++;
			}
		}
	}
	cout<<ans;
	return 0; 
}
