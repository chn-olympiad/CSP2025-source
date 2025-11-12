#include<bits/stdc++.h>
using namespace std;
int a[100005][10],n,t[100005],u[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,t1=0,t2=0,t3=0,ans=0,kl=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)
				scanf("%d",&a[i][j]);
			t[i]=u[i]=0;
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])t1++,t[i]=1;
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])t2++,t[i]=2;
			else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2])t3++,t[i]=3;
		}
		//cout<<t1<<" "<<t2<<" "<<t3<<endl;
		for(int i=1;i<=n;i++)
			ans+=a[i][t[i]];
		if(t1<=n/2&&t2<=n/2&&t3<=n/2){
			cout<<ans<<endl;
			continue;
		}
		int num=0,over=0;
		if(t1>n/2)over=1;
		else if(t2>n/2)over=2;
		else over=3;
		//for(int i=1;i<=n;i++)
			//cout<<t[i]<<endl;
		for(int i=1;i<=n;i++){
			if(t[i]==over){
				if(over==1)u[++num]=a[i][1]-max(a[i][2],a[i][3]),kl++;
				if(over==2)u[++num]=a[i][2]-max(a[i][1],a[i][3]);
				if(over==3)u[++num]=a[i][3]-max(a[i][1],a[i][2]);
				//cout<<i<<" "<<u[num]<<endl;
			}
		}
		//cout<<kl<<" "<<endl;kl=0;
		sort(u+1,u+num+1);
		//cout<<over<<" "<<t1<<" "<<t2<<" "<<t3<<endl;
		if(over==1)over=t1;
		else if(over==2)over=t2;
		else if(over==3)over=t3;
		//cout<<over<<" "<<t1<<" "<<t2<<" "<<t3<<endl;
		//for(int i=1;i<=num;i++)
			//cout<<u[i]<<" ";
		//cout<<u[over-n/2]<<" "<<u[over-n/2+1]<<endl;
		for(int i=1;i<=over-n/2;i++)
			ans-=u[i],kl++;
		cout<<ans<<endl;
	}
	return 0;
}
