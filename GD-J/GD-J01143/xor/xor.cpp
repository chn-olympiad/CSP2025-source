#include<iostream>
#include<cstdio>
using namespace std;
int n,k;
int a[500005];
int cnt[(1<<20)+1],last[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=(1<<20);i++){
		cnt[i]=-1;
	}
	cnt[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]=(a[i]^a[i-1]);
		last[i]=cnt[k^a[i]]+1;
		cnt[a[i]]=i;
	}
	int ans=0,r=0;
	for(int i=1;i<=n;i++){
		if(last[i]>r&&last[i]>0){
			r=i;
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}//I like yuanshen!!!

