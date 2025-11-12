#include<bits/stdc++.h>
using namespace std;
int m;//m¸ùÄ¾¹÷
int shu[5005];
int ass[5005];
int ans; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>shu[i];
		ass[i]=ass[i-1]+shu[i];
	}
	sort(shu+1,shu+1+m);
	for(int k=3;k<=m;k++){
		for(int i=1;i<=m-k+1;i++){
			int j=i+k-1;
			if(ass[j]-ass[i-1]>shu[j]*2){
				ans=(ans+1)%998244353;
				
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
