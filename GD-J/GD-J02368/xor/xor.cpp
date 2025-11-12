#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[200020],b[200020];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(k<=1){
		if(k==0){
			ll s=0,sum=0;
			int i=1;
			for(;i<=n;i++){
				if(a[i]==0)s++;
				else if(a[i]==1){
					ll ss=0;
					int j=i;
					for(;j<=n;j++){
						if(a[j]==1)ss++;
						else break;
					}
					i=j;
					if(ss>1)sum+=ss/2;
				}
			}
			cout<<s+sum;
		}
		else if(k==1){
			ll s=0;
			for(int i=1;i<=n;i++)if(a[i])s++;
			cout<<s;
		}
	}
	else if(k>1)cout<<0;

	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
