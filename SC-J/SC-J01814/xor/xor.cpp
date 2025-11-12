#include<bits/stdc++.h>
using namespace std;
int n,k,c[500002],ans,x[500002];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=500002;i++) x[i]=-1;
	for(int i=1;i<=n;i++)cin>>c[i];
	int a=0,cnt=1;
	for(int i=1;i<=n;i++){
		if(c[i]==k) {
			ans++;
			for(int o=1;o<=cnt;o++){
				x[o]=-1;
			}
			cnt=1;
			continue;
		}
		else {
			a=c[i];
			if(x[cnt-1]==-1){
				x[cnt]=a;
				cnt++;
				continue;
			}
			bool bj=0;
			for(int j=1;j<cnt;j++){
				x[j]=int(x[j]^a);
				if(x[j]==k) {
					bj=1;
					cnt=1;
					ans++;
					for(int o=1;o<=cnt;o++){
						x[o]=-1;
					}
					break;
				}
			}
			if(bj==0) {
				x[cnt]=a;
				cnt++;
			}
		}
	}
	cout<<ans;
	return 0;
}
