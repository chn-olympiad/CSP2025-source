#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int cnt[5],a[100010][5],b[100010],T,n,ans;
/*struct node{
	int v,len=1;
	int id[5];
}p[100010];*/
void dfs(int cur,int s){
	if(cur>n){
		ans=max(ans,s);
		return;
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]+1<=n/2){
			cnt[i]++;
			dfs(cur+1,s+a[cur][i]);
			cnt[i]--;
		}
	}
	return;
}
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=cnt[1]=cnt[2]=cnt[3]=0;
		int f1=1,f2=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				/*if(a[i][j]>p[i].v){
					p[i].id=1;
					p[i].id[1]=j;
					p[i].v=a[i][j];
				}
				*/
			}
			if(a[i][2]!=0) f1=0;
			if(a[i][3]==0) f2=0;
		}
		if(f1==0&f2==0){
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+1+n,cmp);
			for(int i=1;i<=n/2;i++) ans+=b[i];
			cout<<ans<<"\n";
		}
		else{
			dfs(1,0);
			cout<<ans<<"\n";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
