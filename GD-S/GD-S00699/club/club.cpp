#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int ts=t+1;
	int sss[ts];
	for(int i=1;i<=t;i++){
		int n,nt=0;
		cin>>n;
		for(int j=1;j<=n;j++){
		int tt1=0,tt2=0,tt3=0;
		int tts=n+1;
		int tt[tts];
		int sum[4];
		for(int j=1;j<=3;j++){
			cin>>sum[j];
		}
		if(sum[1]>sum[2]&&sum[1]>sum[3]){
		if(tt1<n/2){
		tt[i]=sum[1];
		tt1++;
	}
	else
	{
		if(tt2<n/2&&sum[2]>sum[3]){
			tt[i]=sum[2];
			tt2++;
		}
		if(tt3<n/2){
			tt[i]=sum[3];
			tt3++;
		}
	}
	}
		if(sum[2]>sum[1]&&sum[2]>sum[3]){
		if(tt2<n/2){
		tt[i]=sum[2];
		tt2++;
	}
	else
	{
		if(tt1<n/2&&sum[1]>sum[3]){
			tt[i]=sum[1];
			tt1++;
		}
		if(tt3<n/2){
			tt[i]=sum[3];
			tt3++;
		}
	}
	}
		if(sum[3]>sum[1]&&sum[3]>sum[1]){
		if(tt3<n/2){
		tt[i]=sum[3];
		tt3++;
	}
	else
	{
		if(tt1<n/2&&sum[1]>sum[2]){
			tt[i]=sum[1];
			tt1++;
		}
		if(tt2<n/2){
			tt[i]=sum[2];
			tt2++;
		}
	}
	}
		nt+=tt[i];
	}
		sss[i]=nt;
	}
	for(int i=1;i<=t;i++){
		cout<<sss[i]<<endl;
	}
	return 0;
}
