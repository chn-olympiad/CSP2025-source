#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
int n,x;
int a[N],b[N],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=i;j<=n;j++){
			
			for(int l=i;l<=j;l++){
				sum^=a[l];
			}
			if(sum==x){
				ans++;
			}	
		}
	}
	cout<<ans;
	return 0;
}
