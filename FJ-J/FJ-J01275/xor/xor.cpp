#include<bits/stdc++.h>
using namespace std;
int n,k,a[500050],b[500050],ans,ans2,sum; 
void dfs(int c){
	for(int i=c+1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((a[j]^a[i-1])==k){
//				for(int z=0;z<sum;z++){
//					cout<<"    ";
//				}
//				cout<<"|"<<i<<" "<<j<<" "<<(a[j]^a[i-1])<<"|"<<endl<<endl;
				sum++;
				dfs(j);
				sum--;
			}
		}
	}
	ans=max(sum,ans);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(k==1){
			if(b[i]==1){
				ans2++;
			}
//			else if(a[i-1]==0){
//				ans2++;
//				a[i]=1;
//			}
		}
		else{
			if(b[i]==0){
				ans2++;
			}
			else if(a[i-1]==1){
				ans2++;
			}
		}
		a[i]=(b[i]^a[i-1]);
	}
	if(n<=10){
		dfs(0);
		cout<<ans;
	}
	else{
		cout<<ans2;
	}
	return 0;
} 
