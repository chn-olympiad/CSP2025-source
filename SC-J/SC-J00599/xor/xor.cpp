#include<bits/stdc++.h>
using namespace std;
int z[1000001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,b,ans=0,h=0,bj=0;
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>z[i];
		if(z[i]==b){
			ans++;
			z[i]=-1;
		}
	}
	for(int i=2;i<=a;i++){
		for(int j=1;j<=a;j++){
			h=0;
			bj=0;
			for(int k=j;k<=j+i-2;k++){
				if(z[i]==-1){
					bj=1;
					break;
				}
				h+=z[k]^z[k+1];
			}
			if(h==b&&bj!=1){
				ans++;
				for(int k=1;k<=j+i-1;k++){
					z[k]=-1;
				}
			}	
		}
	}
	cout<<ans;
	return 0;
}