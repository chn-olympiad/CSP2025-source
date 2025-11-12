#include<bits/stdc++.h>
using namespace std;
int n;
int a[100001],vis[100001],vis1[100001],sx[100001],cut,suma[100001];
void dfs(int x){
	if(x>n){
		int sum=0,ma=0;
		for(int i=1;i<=x;i++){
			sum+=sx[i];
			ma=max(ma,sx[i]);
			//cout<<sx[i]<<" ";
			if(sum>ma*2&&suma[sum]==0){
				//cout<<"     "<<sum<<" "<<ma<<endl;
				suma[sum]++;
				return ;
			}
		}
		
		return ;
	}
	for(int i=1;i<=n;i++){
		
		if(vis[i]==0){
			vis[i]=1;
			sx[x]=a[i];
			dfs(x+1);
			
			vis[i]=0;
			sx[x]=0;
		}
		
		
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	for(int i=1;i<=100001;i++){
		if(suma[i]>0){
			cut++;
		}
	}
	cout<<cut;
	return 0;
}

