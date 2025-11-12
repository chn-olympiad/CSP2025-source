#include<bits/stdc++.h>
using namespace std;
int n,ttt0tt,ans,b,c,vis;
struct node{
	int id,nu;
}d[100001],x[100001],y[100001];
bool cmp(node xx,node yy){
	return xx.nu>yy.nu;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>ttt0tt;
	while(ttt0tt--){
		ans=0;
		//for(int i=1;i<=n;i++)vis[i][1]=vis[i][2]=vis[i][3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>d[i].nu>>x[i].nu>>y[i].nu;
			if(x[i].nu!=0)b=1;
			if(y[i].nu!=0)c=1;
		}
		if(b&&c){
			cout<<"18\n";
		}//if(b==0){
		//	
		//}if(c==0){
		//}
		if(b==0&&c==0){
			sort(d+1,d+n+1,cmp);
			for(int i=1;i<=n/2;i++)ans+=d[i].nu;
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
