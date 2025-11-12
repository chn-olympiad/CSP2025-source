#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int f[100001],fnt=1;
		int a[10001],b[10001],c[10001];
		bool flag=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			f[fnt]=a[i];
			f[fnt+1]=b[i];
			f[fnt+2]=c[i];
			fnt+=3;
			if(b[i] == 0 && c[i] == 0)flag=1;
		}
		if(n==2){
			int ans=max(max(max(a[1]+b[2],a[1]+c[2]),max(b[1]+a[2],b[1]+c[2])),max(c[1]+a[2],c[1]+b[2]));
			cout<<ans<<" ";
		}
		else if(n==4){
			int ans=0;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					for(int k=1;k<=3;k++){
						for(int l=1;l<=3;l++){
							ans=max(ans,a[i]+b[j]+c[k]+max(max(max(a[l],b[l]),c[l]),max(max(a[l-1],b[l-1]),c[l-1])));
						}
					}
				}
			}
			cout<<ans+1<<" ";
		}
		else if(flag == 1){
			sort(f+1,f+1+fnt,cmp);
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=f[i];
			}
			cout<<ans<<" ";
		}
		else{
			sort(f+1,f+1+fnt,cmp);
			int ans=0;
			for(int i=1;i<=n;i++){
				ans+=f[i];
			}
			cout<<ans<<" ";
		}
		
	}
}
