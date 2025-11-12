#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int ymyd[N]={0},emyd[N]={0},smyd[N]={0},a=0,b=0,c=0,d=0,s=0,maxn[N]={0},zdzn[N]={0},zj[N]={0},zx[N]={0};
		int n;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>ymyd[j]>>emyd[j]>>smyd[j];
			maxn[j]=max(max(ymyd[j],emyd[j]),smyd[j]);
			zj[j]=min(max(ymyd[j],emyd[j]),smyd[j]);
			zx[j]=min(max(ymyd[j],emyd[j]),smyd[j]);
			if(ymyd[j]>=emyd[j]&&ymyd[j]>=smyd[j]){
				a++;
				zdzn[j]=1;
			}
			if(emyd[j]>=ymyd[j]&&emyd[j]>=smyd[j]){
				b++;
				zdzn[j]=2;
			}
			if(smyd[j]>=ymyd[j]&&smyd[j]>=emyd[j]){
				c++;
				zdzn[j]=3;
			}
			if(emyd[j]==0&&smyd[j]==0) {
				d++;
			}
		}
		while(a<=n/2&&b<=n/2&&c<=n/2){
			if(a>n/2){
				for(int i=1;i<=n;i++){
					if(zj[i+1]<=zj[i]){
						maxn[i]=zj[i];
						zdzn[i]=2;
					}
				}
			}
			if(b>n/2){
				for(int i=1;i<=n;i++){
					if(zx[i+1]<=zx[i]){
						zj[i]=zx[i];
						zdzn[i]=3;
					}
				}
			}
		}
		if(a<=n/2&&b<=n/2&&c<=n/2){
			for(int i=1;i<=n;i++){
				s+=maxn[i];
			}
			cout<<s<<'\n';
		}
		else if(d==n){
			sort(maxn+1,maxn+1+n);
			for(int i=n;i>n/2;i--){
				s+=maxn[i];
			}
			cout<<s<<'\n';
		}
	}
	return 0;
}
