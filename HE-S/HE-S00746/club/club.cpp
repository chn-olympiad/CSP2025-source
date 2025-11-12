#include<bits/stdc++.h>
using namespace std;
const int N=3e5+100;
struct node{
	int per,bu,shu; 
}d[N];
int t,n;
bool vis[N];
bool cmp(node x,node y){
	return x.shu>=y.shu;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int e=1;e<=t;e++){
		memset(vis,false,sizeof(vis));
		cin>>n;
		int mx=n/2,k=1;
		for(int i=1;i<=n;i++){
			cin>>d[k].shu>>d[k+1].shu>>d[k+2].shu;
			d[k].bu=0;
			d[k+1].bu=1;
			d[k+2].bu=2;
			d[k].per=d[k+1].per=d[k+2].per=i;
			k+=3;
		}
		sort(d+1,d+3*n+1,cmp);
		int cn=0,cnt[3],i=1,ans=0;
		for(int j=0;j<3;j++)
			cnt[j]=0;
		while(cn!=n){
			if(vis[d[i].per]){
				i++;
				continue;
			}
			if(cnt[d[i].bu]==mx){
				i++;
				continue;
			}
			ans+=d[i].shu;
			cnt[d[i].bu]++;
			vis[d[i].per]=true;
			cn++;
			i++;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
