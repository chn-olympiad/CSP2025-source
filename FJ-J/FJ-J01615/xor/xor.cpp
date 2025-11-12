#include<bits/stdc++.h>
using namespace std;
int n,k;
int nums[500005][25];
int t[]={0,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576};
int qzt[500005][25];
int cnt=0;
int dis[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		int input;
		scanf("%d",&input);
		for(int j=1;j<=20;j++){
			nums[i][j]=input%2;
			qzt[i][j]=(qzt[i-1][j]+nums[i][j])%2;
			input/=2;
		}
	}	
	for(int len=1;len<=n;len++){
		for(int l=1;l<=n-len+1;l++){
			int r=l+len-1;
			int flag=0;
			for(int i=l;i<=r;i++)
				if(dis[i]==1) flag=1;
			if(flag) continue;
			int nnum=0;
			int nn[25];
			for(int i=1;i<=20;i++){
				nn[i]=(qzt[l-1][i]+qzt[r][i])%2;
				nnum+=t[i]*nn[i];
			}
			if(nnum==k){
				for(int i=l;i<=r;i++) dis[i]=1;
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
