#include<bits/stdc++.h>
using namespace std;
long long n,k,a,ans,sum[1000001],l[1000001],r[1000001],m;
bool c;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		sum[i]=sum[i-1]^a;
	}
	for(long long i=1;i<n;i++){
		for(int j=1;j<=i;j++){
			for(int x=1;x<=n;x++){
				for(int y=x;y<=n;y++){
					c=0;
					for(int b=1;b<=m;b++){
						if((x>=l[b]&&x<=r[b])||(y>=l[b]&&y<=r[b])){
							c=1;
							break;
						}
					}
					if(c==1){
						break;
					}
					if(sum[y]^sum[x-1]!=k){
						break;
					}
					m++;
					l[m]=x;
					r[m]=y;
				}
			}
		}
		for(int j=1;j<=m;j++){
			l[j]=0;
			r[j]=0;
		}
		m=0;
		if(c==0){
			ans=max(i,ans);
		}
	}
	cout<<ans;
	return 0;
}
