#include<bits/stdc++.h>
using namespace std;
int add[500010],n,k,lon[500010],ans=0;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",add+i);
		add[i]=add[i]^add[i-1];
	}
	for(int i=n;i>=1;i--){
		for(int l=i;l<=n;l++){
			if(lon[l]>0)break;
			if((add[l]^add[i-1])==k){
				lon[i]=(l-i+1);
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
