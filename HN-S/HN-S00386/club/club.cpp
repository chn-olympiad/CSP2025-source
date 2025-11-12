#include<bits/stdc++.h>
using namespace std;
int n;
int suma=0,sumb=0,sumc=0,summ=0,ans=0,cnt=0;
int a[100001][4],b[100005],c[100005];
void dfs(int d,int num){
	cnt++;
	if(cnt>260000000/n){
		ans=max(ans,summ);
//		return;
	}
	summ+=a[d][num];
	if(d==n+1||suma+sumb+sumc==n){
		ans=max(ans,summ);
		summ-=a[d][num];
		return;
	}
	if(suma+1<=n/2){
		suma++;
		dfs(d+1,1);
		suma--;
	}
	if(sumb+1<=n/2){
		sumb++;
		dfs(d+1,2);
		sumb--;
	}
	if(sumc+1<=n/2){
		sumc++;
		dfs(d+1,3);
		sumc--;
	}
	summ-=a[d][num];
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		bool flag2=1,flag3=1;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			b[i]=a[i][1];
			c[i]=a[i][2];
			if(a[i][2]) flag2=0;
			if(a[i][3]) flag3=0;
		}
		if(n<=10){
			suma=0,sumb=0,sumc=0,summ=0,ans=0,cnt=0;
			
			summ=0,suma=0,sumb=0,sumc=0,cnt=0;
			suma++;
			dfs(1,1);
			
			summ=0,suma=0,sumb=0,sumc=0,cnt=0;
			sumb++;
			dfs(1,2);
			
			summ=0,suma=0,sumb=0,sumc=0,cnt=0;
			sumc++;
			dfs(1,3);
			cout<<ans<<"\n";
		}
		else{
			if(flag2&&flag3){
				sort(b+1,b+n+1);
				for(int i=n;i>n/2;i--){
					ans+=b[i];
				}
				cout<<ans<<"\n";
			}
		}
	}
	return 0;
}

