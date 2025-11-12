#include<bits/stdc++.h>
using namespace std;
const int MAXN=5*1e5+5;
int n,k,a[MAXN],sx[MAXN],ansd;
bool check(int x){
	int lst=0,num=0;
	for(int i=1;i<=x;i++){
		bool flag=1;
		for(int e=lst+1;e<=n&&flag;e++){
			for(int len=1;len<=e-lst;len++){
				int s=e-len+1;
				int t=sx[e]^sx[s-1];
				if(t==k){
					lst=e;
					num++;
					flag=0;
					break;
				}
			}
		}
		if(flag){
			break;
		}
	}
	if(num>=x){
		return 1;
	}else{
		return 0;
	}
}

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==k){
			ansd++;
		}
		sx[i]=sx[i-1]^a[i];
	}
	int L=0,R=n+1;
	while(L+1<R){
		int M=(L+R)/2;
		if(check(M)){
			L=M;
		}else{
			R=M;
		}
	}
	printf("%d",L);
	return 0;
}
