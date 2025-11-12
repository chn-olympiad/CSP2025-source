#include<bits/stdc++.h>
using namespace std;
int mg[5005];
int n;
int ans=0;
void polygon(int m,int r,int cnt,int flag){
	//cout<<m<<" ";
	if(r==0){
		ans++;
		if(ans>=998244353) ans-=998244353;
		//cout<<endl;
		return;
	} 
	for(int i=flag;i<=n-r;i++){ 
		if(r==1){
			if(mg[i+1]>=cnt){
			    //cout<<endl;
				return;
			}
			//cout<<i+1<<" ";
			else polygon(mg[i+1],r-1,mg[i+1]+cnt,i+1);
		}
		else{
			//cout<<i+1<<" ";
			polygon(mg[i+1],r-1,mg[i+1]+cnt,i+1);
		}
	}
	//return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>mg[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-1;j++){
			if(mg[j]>mg[j+1]) swap(mg[j],mg[j+1]);
		}
	}
	for(int i=2;i<=n-1;i++){
		for(int j=1;j<=n-i;j++){
			polygon(mg[j],i,mg[j],j);
		}
	}
	
	cout<<ans;
}
