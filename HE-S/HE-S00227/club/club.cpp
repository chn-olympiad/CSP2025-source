#include<bits/stdc++.h>
using namespace std;
int one2[100500],two2[100500],three2[100500];
int ans[10];
struct student{
	int one,two,three;
	int maxx,bh;
}cy[100500],c[100500];
int t,n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a=n/2;
		int one1=a,two1=a,three1=a;
		for(int i=1;i<=n;i++){
			cin>>cy.one[i]>>cy.two[i]>>cy.three[i];
		}
		for(int i=1;i<=n;i++){
			int b=max(cy.one[i],cy.two[i]);
			c.maxx[i]=max(b,cy.three[i]);
			if(c.maxx[i]==cy.one[i]){
				c.bh[i]=1;
			}
			if(c.maxx[i]==cy.two[i]){
				c.bh[i]=2;
			}
			if(c.maxx[i]==cy.three[i]){
				c.bh[i]=3;
			}
		}
		for(int i=1;i<=n;i++){
			if(c.bh[i]==1){
				one2[i]=c.maxx[i];
			}
			if(c.bh[i]==2){
				two2[i]=c.maxx[i];
			}
			if(c.bh[i]==3){
				three2[i]=c.maxx[i];
			}
		}
		for(int i=1;i<=n;i++){
			ans[t]=one2[i]+two2[i]+three2[i];
		}
	}
	for(int i=t;i>=1;i--){
		cout<<ans[i]<<endl;
	}
	return 0;
}
