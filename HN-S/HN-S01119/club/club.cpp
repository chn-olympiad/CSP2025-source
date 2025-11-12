#include<bits/stdc++.h>
using namespace std;
long long data9[100009][3],n,t;
long long ki1(long long now,long long nowa,long long nowb,long long nowc,long long nowans){
	if(now>n){
		return nowans;
	}else{
		long long temp1=0,temp2=0,temp3=0,temp4=0;
		if(nowa<n/2&&data9[now][0]!=0){
			temp1=ki1(now+1,nowa+1,nowb,nowc,nowans+data9[now][0]);
		}
		if(nowb<n/2&&data9[now][1]!=0){
			temp2=ki1(now+1,nowa,nowb+1,nowc,nowans+data9[now][1]);
		}
		if(nowc<n/2&&data9[now][2]!=0){
			temp3=ki1(now+1,nowa,nowb,nowc+1,nowans+data9[now][2]);
		}
		temp4=ki1(now+1,nowa,nowb,nowc,nowans);
		return max(max(temp1,temp4),max(temp2,temp3));
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		n=0;
		cin>>n;
		for(long long j=1;j<=n;j++){
			data9[j][0]=0;
			data9[j][1]=0;
			data9[j][2]=0;
			cin>>data9[j][0]>>data9[j][1]>>data9[j][2];
		}
		cout<<ki1(1,0,0,0,0)<<endl;
	}
	return 0;
}
