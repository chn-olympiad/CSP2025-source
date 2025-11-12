#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int ans[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	int n,k,ansa=0,cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int l=1;l<=n;l++)
		for(int r=n;r>=l;r--){
			int sum=0;
			for(int i=l;i<=r;i++)
				sum=sum^a[i];
			if(sum==k)
				ans[l]=r;
		}
	for(int i=1;i<=n;i++){
		if(ans[i]!=0){
		//	cout<<i<<" "<<ans[i]<<"    "; 
			int anss=1;
			for(int j=ans[i]+1;j<=n;j++)	//左端点 
				if(ans[j]!=0){
					anss++;
				//	cout<<i<<"  "<<j<<" "<<ans[j]<<"\n";
					j=ans[j]+1;
				}
			ansa=max(ansa,anss);
		}
	}
	cout<<ansa;
	return 0;
}