#include<bits/stdc++.h>
using namespace std;
int a[10050],c1[10050],c2[10050],c3[10050],ans,a1,a2,a3,b1[1050],b2[1050],b3[1050],b4[1050],b5[1050],b6[1050],T,n,m,ma;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("clud.in","r",stdin);
	freopen("clud.out","w",stdout);
	cin>>T;
	for(int t=1;t<=T;t++){
		ans=0;
		for(int i=1;i<=n;i++){
			c1[i]=0;
			c2[i]=0;
			c3[i]=0;
		}
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>c1[i]>>c2[i]>>c3[i];
			b1[i]=c1[i]-c2[i];
			b2[i]=c2[i]-c3[i];
			b3[i]=c1[i]-c3[i];
			b4[i]=b1[i]+b3[i];
			b5[i]=b2[i]+b3[i];
			b6[i]=b2[i]-b1[i];
			if(c1[i]==0){
				a1++;
			}
			if(c2[i]==0){
				a2++;
			}
			if(c3[i]==0){
				a3++;
			}
		}
		if(a1==n&&a2==n){
			sort(c3+1,c3+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans=ans+c3[i];
			}
			cout<<ans;
			break;
		}
		if(a1==n&&a3==n){
			sort(c2+1,c2+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans=ans+c2[i];
			}
			cout<<ans;
			break;
		}
		if(a3==n&&a2==n){
			sort(c1+1,c1+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans=ans+c1[i];
			}
			cout<<ans;
			break;
		}
		if(a1==n){
			for(int i=1;i<=n/2;i++){
				m=0;
				for(int j=1;j<=n;j++){
					if(b2[m]<b2[j]&&a[j]==0){
						m=j;
					}
				}
				ans=ans+c2[m];
				a[m]=1;
			}
			for(int j=1;j<=n;j++){
				if(a[j]==0)
					ans=ans+c2[j];
			}
			cout<<ans;
			break;
		}
		if(a2==n){
			for(int i=1;i<=n/2;i++){
				m=0;
				for(int j=1;j<=n;j++){
					if(b3[m]<b3[j]&&a[j]==0){
						m=j;
					}
				}
				ans=ans+c1[m];
				a[m]=1;
			}
			for(int j=1;j<=n;j++){
				if(a[j]==0)
					ans=ans+c3[j];
			}
			cout<<ans;
			break;
		}
		if(a1==n){
			for(int i=1;i<=n/2;i++){
				m=0;
				for(int j=1;j<=n;j++){
					if(b2[m]<b2[j]&&a[j]==0){
						m=j;
					}
				}
				ans=ans+c1[m];
				a[m]=1;
			}
			for(int j=1;j<=n;j++){
				if(a[j]==0)
					ans=ans+c3[j];
			}
			cout<<ans;
			break;
		}
		for(int i=1;i<=n/2;i++){
			m=0;
			for(int j=1;j<=n;j++){
				if(b4[m]<b4[j]&&a[j]==0){
					m=j;
				}
			}
			ans=ans+c1[m];
			a[m]=1;
		}
		for(int i=1;i<=n/2;i++){
			m=0;
			for(int j=1;j<=n;j++){
				if(b6[m]<b6[j]&&a[j]==0){
					m=j;
				}
			}
			ans=ans+c2[m];
			a[m]=1;
		}
		for(int i=1;i<=n;i++){
			if(a[i]==0)
				ans=ans+c3[i];
		}
		cout<<ans; 
	}
	return 0;
}
