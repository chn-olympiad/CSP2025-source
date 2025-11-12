#include<bits/stdc++.h>
using namespace std;
int n,m,ax,ay,num,t[27],k[27],a[500007],b[500007],c[500007];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	int tt=0,d=m;
	while(d){
		t[++tt]=d%2;
		d/=2;
	}
	
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int ans=0,anx=0,r=0,l=1,oo=a[i],ll=1;
		if(a[i]==m){
			num++;
			for(int j=1;j<=24;j++) k[j]=0;
			for(int j=1;j<=ax;j++) c[b[j]]--;
			ax=0;
			continue;
		}
		if(a[i]==0) continue;
		while(a[i]){
			k[ll++]^=a[i]%2;
			a[i]/=2;
		}
		for(int j=1;j<=20;j++) if(k[j]==1) ll=max(j,ll);
		ans=max(tt,ll);
		while(r!=ans){
			if(t[++r]!=k[++r]) anx+=l;
			l*=2;
		}
		if(anx==0){
			num++;
			for(int j=1;j<=24;j++) k[j]=0;
			for(int j=1;j<=ax;j++) c[b[j]]--;
			ax=0;
			continue;
		}
		if(c[anx]){
			num++;
			for(int j=1;j<=24;i++) k[j]=0;
			for(int j=1;j<=ax;i++) c[b[j]]--;
			ax=0;
			continue;
		}
		b[++ax]=oo^b[ax-1];
		c[b[ax]]++;
	}
	cout<<num;
	return 0;
} 
