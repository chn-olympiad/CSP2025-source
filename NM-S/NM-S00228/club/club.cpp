#include<bits/stdc++.h>
using namespace std;
int t;
const int N=1e5+19;
int n[N],g;
int a[N];
int sum1[N],sum2[N],sum3[N];
int ans[N];
int maxx[N],mmxx[N],minn[N];
int b1[N],b2[N],b3[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(g<t){
		cin>>n[g];
		
		for(int i=1;i<=n[g];i++){
			cin>>b1[i]>>b2[i]>>b3[i];
				maxx[i]=max(b1[i],b2[i]);
			maxx[i]=max(maxx[i],b3[i]);
			minn[i]=min(b1[i],b2[i]);
			minn[i]=min(minn[i],b3[i]);
			if(maxx[i]==b1[i]&&minn[i]==b2[i]){
				mmxx[i]=b3[i];
			} 
			if(maxx[i]==b2[i]&&minn[i]==b1[i]){
				mmxx[i]=b3[i];
			} 
			if(maxx[i]==b2[i]&&minn[i]==b3[i]){
				mmxx[i]=b1[i];
			} 
			if(maxx[i]==b3[i]&&minn[i]==b2[i]){
				mmxx[i]=b1[i];
			} 
			if(maxx[i]==b1[i]&&minn[i]==b3[i]){
				mmxx[i]=b2[i];
			} 
			if(maxx[i]==b3[i]&&minn[i]==b1[i]){
				mmxx[i]=b2[i];
			} 
//			cout<<maxx[i]<<" "<<mmxx[i]<<" "<<minn[i]<<endl;
				if(n[g]==2){
			ans[g]=max(b1[1]+b2[2],b1[1]+b3[2]);
			ans[g]=max(ans[g],b2[1]+b3[2]);	
			ans[g]=max(ans[g],b2[1]+b1[2]);	
			ans[g]=max(ans[g],b3[1]+b1[2]);	
			ans[g]=max(ans[g],b3[1]+b2[2]);	
			cout<<ans[g]<<endl;
			continue;	
			
		}
			if(maxx[i]==b1[i]){
				sum1[g]++;
//				cout<<sum1[g]<<endl;
			}
			else if(maxx[i]==b2[i]){
				sum2[g]++;
//				cout<<sum2[g]<<endl;
			}
			else{
				sum3[g]++;
//				cout<<sum3[g]<<endl;
			}

//			if(sum1[g]<=(n[g]/=2)&&sum2[g]<=n[g]/2&&sum3[g]<=n[g]/2){

			ans[g]+=maxx[i];
			if(i==n[g]){
				cout<<ans[g]<<endl;
				}
//			}
//			else{
//				continue;
//			}
		}
	g++;
	}

	return 0;
}
