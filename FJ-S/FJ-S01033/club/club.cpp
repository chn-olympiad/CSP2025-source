#include<bits/stdc++.h>
using namespace std;
int n,t;
bool f1=true,f2=true;
int a[100010],b[100010],c[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]!=b[i]) f1=false;	
			if(c[i]!=0) f2=false;
		}
		if(f1){
			int ans=0;
			for(int i=1;i<=n;i++) ans+=a[i];
			cout<<ans<<endl;
		}
		if(f2){
			int x[100010][2],y[100010][2];
			int ans=0,ans1=0,ans2=0;
			for(int i=1;i<=n;i++){
				x[i][0]=a[i];
				x[i][1]=b[i];
				y[i][0]=b[i];
				y[i][1]=a[i];
			}
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					if(x[i][0]<x[i][1]) swap(x[i],x[j]);
					if(y[i][0]<y[i][1]) swap(y[i],y[j]);
				}
			}
			for(int i=1;i<=n;i++){
				if(i<=n/2){
					ans1+=x[i][0];
					ans2+=y[i][0];
				}
				else{
					ans1+=x[i][1];
					ans2+=y[i][1];
				}
			} 
			ans=max(ans1,ans2);
			cout<<ans<<endl;
		}
	} 
	return 0;

}

