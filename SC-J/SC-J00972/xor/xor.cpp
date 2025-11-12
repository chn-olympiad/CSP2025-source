#include<bits/stdc++.h>
using namespace std;

const int N=5e5+7;
int n,k,sum[N],stack_[N],top=0,ans=0;
bool t[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		sum[i]=sum[i-1]^x;
	}
	t[0]=true;
	stack_[++top]=0;
	for(int i=1;i<=n;i++){
		if(t[k^sum[i]]){
			while(top){
				t[stack_[top--]]=false;
			}
			stack_[++top]=sum[i];
			t[sum[i]]=true;
			ans++;
		}else{
			t[sum[i]]=true;
			stack_[++top]=sum[i];		
		}
	}
	printf("%d",ans);
	return 0;
}