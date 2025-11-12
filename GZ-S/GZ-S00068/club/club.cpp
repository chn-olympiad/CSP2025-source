//GZ-S00068 北京师范大学贵阳附属中学 刘雨航 
#include<bits/stdc++.h>
using namespace std;
struct man{
	int id,lk;
};
bool cmp(man a,man b){
	if(a.lk>b.lk)return true;
	else return false;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,na=0,nb=0,nc=0,d[10005]={},e[10005]={},nn,ans=0;
		man a[10005]={},b[10005]={},c[10005]={};
		cin>>n;
		nn=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].lk>>b[i].lk>>c[i].lk;
			a[i].id=i;
			b[i].id=i;
			c[i].id=i;
			if(a[i].lk>b[i].lk&&a[i].lk>c[i].lk){
				d[i]=1;
				if(b[i].lk>c[i].lk)e[i]=2;
				else e[i]=3;
			}
			else  if(b[i].lk>a[i].lk&&b[i].lk>c[i].lk){
				d[i]=2;
				if(a[i].lk>c[i].lk)e[i]=1;
				else e[i]=3;
			}
			else  {
				d[i]=3;
				if(b[i].lk>a[i].lk)e[i]=2;
				else e[i]=1;
			}
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		for(int i=1;i<=n;i++){
		if(d[a[i].id]==1&&na<nn){ans+=a[i].lk;d[i]=0;e[i]=0;na++;}
		else if(d[b[i].id]==2&&nb<nn){ans+=b[i].lk;d[i]=0;e[i]=0;nb++;}
		else if(d[c[i].id]==3&&nc<nn){ans+=c[i].lk;d[i]=0;e[i]=0;nc++;}
		}cout<<na<<" "<<nb<<" "<<nc<<" ";
		for(int i=1;i<=n;i++){
		if(e[a[i].id]==1&&na<nn){ans+=a[i].lk;e[i]=0;na++;}
		else if(e[b[i].id]==2&&nb<nn){ans+=b[i].lk;e[i]=0;nb++;}
		else if(e[c[i].id]==3&&nc<nn){ans+=c[i].lk;e[i]=0;nc++;}
		}
		cout<<ans<<endl;
	}
	return 0;
}

