#include<bits/stdc++.h>
using namespace std;
int a[500005];
int ans[500005][2];
int f[10005];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	int n,k,ji=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			int sum=a[j];
			for(int dd=j+1;dd<=i;dd++){
				sum=~(sum^a[dd]);
			}
			if(sum==k){
				//cout<<i<<" "<<j<<endl;
				ans[ji][0]=j;
				ans[ji][1]=i;
				ji++;
			}
		}
	}
	for(int i=1;i<=ji;i++){
		for(int j=1;j<=i;j++){
			if(ans[i][1]<=ans[j][1]){
				swap(ans[i][0],ans[j][0]);
				swap(ans[i][1],ans[j][1]);
			}
		}
	}
	int ks=0;
	for(int i=1;i<=ji;i++){
		bool a=1;
		for(int j=1;j<=ks;j++){
			if(ans[f[j]][0]<=ans[i][1]&&ans[f[j]][1]>=ans[i][0]){
				//cout<<"no"<<endl;
				a=0;
				break;
			}
		}
		if(a==1){
			ks++;
			f[ks]=i;
			//cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
		}
	}
	//cout<<"0";
	cout<<ks;
	return 0;
}
//AFO???