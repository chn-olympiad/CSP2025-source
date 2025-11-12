#include<bits/stdc++.h>
using namespace std;
int a[500005],num[500005][25],sum[500005][25],knum[25],b[500005][25];
//存二进制 
/*
想了两个小时，才发现思路根本就是错的
 或许，OIER的梦......
 该醒了....... 
 在OI里，我到底得到了些什么啊？
  初中学了一年多，小学学了两年，
  奖项没多少， 也没啥天赋，
   和别人表白又搞得一塌糊涂
   我到底应不应该坚持下去OI？ 
*/
int main(){
	//freopen() 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int t=a[i],now=25;
		while(1){
			num[i][now]=t%2;
			now--;
			t/=2;
			if(t==0)break;
		}
	}
	int tk=k,now=25;
	while(1){
		knum[now]=tk%2;
		now--;
		tk/=2;
		if(tk==0)break;
	} 
	for(int i=25;i>=1;i--)sum[1][i]=num[1][i];
	for(int i=2;i<=n;i++){
		for(int j=1;j<=21;j++){
			sum[i][j]=sum[i-1][j]^num[i][j];
			if(sum[i][j]==1&&sum[i-1][j]==1||sum[i][j]==0&&sum[i-1][j]==1)b[i][j]=!knum[j];
			else b[i][j]=knum[j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			bool f=0;
			for(int k=1;k<=21;k++){
				if(b[i][k]!=sum[j][k]){
					f=1;
					break;
				}
			}
			if(f==0)ans++;
		}
	}
	cout<<ans;
	return 0;
}
/*
4 3
2 1 0 3*/
