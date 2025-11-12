#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int c[100005];
int ans=0,n=0,k=0;
bool comp(int x,int y){
	return x>y;
}
void check(int x,int num,int df1,int df2,int df3){
	if(df1>k||df2>k||df3>k) return;
	if(x==n){
		if(df1<=k&&df2<=k&&df3<=k){
			ans=max(ans,num);
		}
		return;
	}
        df1++;
		check(x+1,num+a[x+1],df1,df2,df3);
		df1--;
		df2++;
		check(x+1,num+b[x+1],df1,df2,df3);
		df2--;
		df3++;
		check(x+1,num+c[x+1],df1,df2,df3);
		df3--;
}
void dfs(){
	cin>>n;
	k=n/2;
	ans=0;
	for(int i=1;i<=n;i++) {
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	}
	if(n<=30) check(0,0,0,0,0);
	else {
		if(b[1]==c[1]==0){
			sort(a+1,a+n+1,comp);
		    for(int i=1;i<=k;i++) ans+=a[i];
		    cout<<ans;
		}
		else {
			for(int i=1;i<=n;i++){
				ans+=max(a[i],max(b[i],c[i]));
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) dfs();
	return 0;
} 
