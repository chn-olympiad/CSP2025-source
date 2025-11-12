#include<bits/stdc++.h>
using namespace std;
int n,t,vis[100005],maxx1=1,maxx2=1,maxx3=1,ans=0,f=0,j=1,a[100005],b[100005],c[100005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		j=1;
		memset(vis,0,sizeof(vis));
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
		sort(a+1,a+1+n,cmp);
		sort(c+1,c+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		for(int i=1;i<=n;i+=3){
			if(i+3>=n){
				if(n-i==1)ans+=max(a[j],max(b[j],c[j]));
				else{
					ans+=max(a[j],max(b[j],c[j]));
					if(a[j]==max(a[j],max(b[j],c[j])))a[j]=0;
					else if(b[j]==max(a[maxx1],max(b[j],c[j])))b[j]=0;
					else if(c[j]==max(a[j],max(b[j],c[j])))c[j]=0;
					ans+=max(a[j],max(b[j],c[j]));
				}
			}
			else ans=a[j]+b[j]+c[j]+ans;
			j++;
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
