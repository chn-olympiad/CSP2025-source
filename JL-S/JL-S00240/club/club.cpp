#include<bits/stdc++.h>
using namespace std;
#define int long long
int l[500000][5];
int t,n,s;
int cf=0,cs=0,ct=0;
int ans[200000],a[200000],b[200000],c[200000],d[200000];
map<int,int> mp;
signed main(){
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
       cin>>t;
       for(int k=1;k<=t;++k){
		   cin>>n;
       for(int i=1;i<=n;++i){
		   for(int j=1;j<=3;++j){
			   cin>>l[i][j]>>s;
			   if(j==1){a[i]=l[i][j];     cf+=a[i];}
			   if(j==2){b[i]=l[i][j];     cs+=b[i];}
			   if(j==3){c[i]=l[i][j];     ct+=c[i];}
	   }}
        int q;
	    q=max(cf,max(cs,ct));
        if(q==cf){
			sort(a+1,a+1+n);
			for(int i=1;i<=n/2;++i){
				cf-=a[i];
				d[i]=a[i];
				}
			for(int i=1;i<=n;++i){
				if(l[i][1]==d[i]){mp[c[i]]=1;mp[b[i]]=1;}
				}
			for(int i=1;i<=n;++i){
				for(int j=1;j<=3;++j){
					if(j==2&&mp[b[i]]!=1){ans[i]=ans[i-1]+b[i];}
					if(c[i]>b[i]&&mp[c[i]]!=1){ans[i]=ans[i]+c[i]-b[i];}
					}
			}
			cout<<cf+ans[n]<<endl;
			}//a
         if(q==cs){
			sort(b+1,b+1+n);
			for(int i=1;i<=n/2;++i){
				cs-=b[i];
				d[i]=b[i];
				}
			for(int i=1;i<=n;++i){
				if(l[i][2]==d[i]){mp[c[i]]=1;mp[a[i]]=1;}
				}
			for(int i=1;i<=n;++i){
				for(int j=1;j<=3;++j){
					if(j==1&&mp[a[i]]!=1){ans[i]=ans[i-1]+a[i];}
					if(c[i]>a[i]&&mp[c[i]]!=1){ans[i]=ans[i]+c[i]-a[i];}
					}
			}
			cout<<cs+ans[n]<<endl;
			}
         if(q==ct){
			sort(c+1,c+1+n);
			for(int i=1;i<=n/2;++i){
				ct-=c[i];
				d[i]=c[i];
				}
			for(int i=1;i<=n;++i){
				if(l[i][3]==d[i]){mp[b[i]]=1;mp[a[i]]=1;}
				}
			for(int i=1;i<=n;++i){
				for(int j=1;j<=3;++j){
					if(j==1&&mp[a[i]]!=1){ans[i]=ans[i-1]+a[i];}
					if(b[i]>a[i]&&mp[b[i]]!=1){ans[i]=ans[i]+b[i]-a[i];}
					}
			}
			cout<<ct+ans[n]<<endl;
			}
}
return 0;
}
