#include<bits/stdc++.h>
using namespace std;
int const N=5e5+1;
int a[N]={},d[N]={};
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out ","w",stdout);
//    int a=1,b=0,c=3; 
//	int ans=a^b^c;
//	cout<<ans;
	int n,k,ans=0,s=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		
		cin>>a[i];
	}
	//cout<<find(2,4)<<" ";
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int cnt=0;
			for(int k=i;k<=j;k++){
				cnt=cnt^a[k]; 
			}
			if(cnt==k){
				int f=1;
				for(int x=1;x<=s;x++){
					if(d[x]==i||d[x]==j){
						f=0;
					}
				}
				if(f){
					d[s]=i;
					d[s+1]=j;
					s+=2;
					ans++;
					//cout<<i<<" "<<j<<"\n";	
				}
				
			}
		} 
	} 
	cout<<ans;
	return 0;
}