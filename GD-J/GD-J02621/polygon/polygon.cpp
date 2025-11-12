#include<bits/stdc++.h>
using namespace std;
int n;
long long a[5005],cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdin);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				long long sum=0,maxn,x,y;
				sum+=a[i];
				sum+=a[j];
				sum+=a[k];
				maxn=max(max(a[i],a[k]),a[j]);
				//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" ";
				if(sum>maxn*2){
					cnt++;
					//cout<<"YES";
					x=sum;
					y=maxn;
				}
				for(int l=k+1;l<=n;l++){
					sum+=a[l];
					maxn=max(maxn,a[l]);
					//cout<<a[l]<<" ";
				}
				//cout<<"    "<<maxn<<" "<<sum<<" ";
				if(sum>maxn*2&&x!=sum&&y!=maxn){
					cnt++;
					//cout<<"YES";
				}
				//cout<<endl;
			}
		}
	}
	cout<<cnt%998244353;
	return 0;
}
