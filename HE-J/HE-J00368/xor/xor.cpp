#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[500050];
int s[500050];
int ans=0;
inline void solve(int x,int sum,int l){
	if(x==1){
//		if(s[1]==k){
//			sum++;
//		}
		solve(x+1,sum,l+1);
		if(s[1]==k){
			solve(x+1,sum+1,1);
		}else{
			solve(x+1,sum,1);
		}
		
	}
	if(x>n){
		ans=max(ans,sum);
		//printf("\n%d\n",ans);
		return;
	}
	solve(x+1,sum,l+1);
	if(s[x]|s[x-l+1]==k){
		solve(x+1,sum+1,1);
	}else{
		solve(x+1,sum,1);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	int sum1=0,sum0=0;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		if(a[i]==1) sum1++;
		if(a[i]==0) sum0++;
		if(i == 1){
			s[i]==a[i];
		}else{
			s[i]=s[i-1]^a[i];
		}
	}

	if(k!=0||k!=1){
		printf("0\n");	
		return 0;	
	}else{
		if(k==1){
			printf("%d",n);
			return 0;
		}
		else if(k==0){
			printf("%d",n/2);
			return 0;
		}
	}
	
	return 0;
}

