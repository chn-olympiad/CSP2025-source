#include<bits/stdc++.h>
using namespace std;
int a[1000005],b[1000005],ans=0;
int sb(int x,int y){
	for(int i=y;i>=y-x;i--){
		if(a[i]==-1||b[i]==-1){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1&&b[i-1]!=-1){
			b[i]=a[i]^a[i-1];
		}
		if(a[i]==k){
			ans++;
			a[i]=-1;
			b[i]=-1;
		} 
	}
	for(int i=2;i<=n;i++){
		int flag=b[2];
		int t=1;
		for(int k=n;k>=1;k--){
			if(b[k]!=-1){
				t=0;
				break;
			}
		}
		if(t){
			break;
		}
		for(int j=i;j<=n;j++){
			if(b[j]==k&&a[j]!=-1){
				ans++;
				for(int k=j;k>j-i;k--){
					a[k]=-1;
					b[k]=-1;
				}
			}else if(sb(i,j)){
				b[j]=flag;
				flag=b[j]^a[j+1];
			}else{
				b[j]=-1;
			}
		}
	}
	cout<<ans;
	return 0;
}
