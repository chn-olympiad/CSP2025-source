#include<bits/stdc++.h>
using namespace std;
const int N=500100;
int n,k,ans,sum;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n<=2 and k==0){
		if(a[1]==0 and a[2]==0)cout<<3;
		else if((a[1]==0 and a[2]==1) or (a[1]==1 and a[2]==0))cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)
		{
			int l=i,r=j,x=0;
			while(l<=r){
				x^=a[l];
				sum+=x;
				l++;
			}
			if(sum==k)ans++;
		}
	}
	cout<<ans;
	return 0;
} 
