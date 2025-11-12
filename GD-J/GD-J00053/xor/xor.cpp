#include<bits/stdc++.h>
using namespace std;
int a[500005],sum[500005];
bool used[500005];
int n,k;
bool check(int num){
	for(int i=1;i<=n-num+1;i++){
		if(sum[i]!=-1) return true;
	}
	return false;
}
void solve1(){
	if(k==1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]) cnt++;
		}
		printf("%d",cnt);
	}else if(k==0){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]){
				if(a[i+1]){
					cnt++;
					i++;
				}
				else{
					cnt++;
					i++;
				}
			}else cnt++;
		}
		printf("%d",cnt);
	}
	return ;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(sum,0,sizeof(sum));
	memset(used,false,sizeof(used));
	int maxx=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxx=max(maxx,a[i]);
	}
	if(maxx==1||maxx==0) solve1();
	else{
		int ans=0;
		for(int i=1;i<=n;i++){
			memset(sum,0,sizeof(sum));
			
			for(int j=1;j<=n-i+1;j++){
				if(used[j]) continue;
				for(int ii=1;ii<=i;ii++){
					if(used[j+ii-1]){
						sum[j]=-1;
						break;
					}
					sum[j]^=a[j+ii-1];
				}
//				printf("%d-%d:%d\n",j,j+i-1,sum[j]);
				if(sum[j]==k){
					for(int ii=1;ii<=i;ii++){
						used[j+ii-1]=1;
					}
					ans++;
				}
			}
//			if(!check(i)) break;
		}
		printf("%d\n",ans);
	}
	
	return 0;
}

