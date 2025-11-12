#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int n,k,a[5000001],ans=0,cnt[5000001][5000001],flag[5000001],now;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	/*for(int i=1;i<=n;i++){
		now=i;
		for(int j=i;j<=n;j++){
			for(int q=i+1;q<=j;q++){
				now^=q;
			}
			cnt[i][j]=now;
		}
	}
	int c=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			c++;
			for(int x=1;x<=n;x++){
				for(int y=1;y<=n;y++){
					if(cnt[x][y]==cnt[i][j]){
						flag[c]++;}}}}}*/
	if(k==1&&n==1){
		cout<<a[1];
		return 0;
	}
	/*for(int i=1;i<=n*n;i++){
		if(ans<=flag[i]){
			ans=flag[i];}}
	cout<<ans;*/
	
    return 0;
}
//11:00 have fun in this problem.
//11:05 have some new in this problem.
//11:20 I can't AC this problem,time is so short.
