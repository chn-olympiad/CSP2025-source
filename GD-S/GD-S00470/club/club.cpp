#include<bits/stdc++.h>
using namespace std;
int t,n,maid,mbid,mcid,suma,sumb,sumc;
int a[100005],b[100005],c[100005];
int maxa=-99,maxb=-99,maxc=-99;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int i=1;i<=n/3;i++){
			
			for(int i=1;i<=n;i++){
				if(a[i]>maxa){
					maxa=a[i];
					maid=i;
				}				
			}		
			suma=suma+a[maid];
			a[maid]=0;
			for(int i=1;i<=n;i++){
				if(b[i]>maxb){
					maxb=b[i];
					mbid=i;
				}				
			}
			sumb=sumb+b[maid];
			b[maid]=0;
			for(int i=1;i<=n;i++){
				if(c[i]>maxc){
					maxc=c[i];
					mcid=i;
				}				
			}		
			sumc=sumc+c[maid];
			c[maid]=0;			
		}
		if(n%3==1){
			for(int i=1;i<=n;i++){
				if(a[i]>maxa){
					maxa=a[i];
					maid=i;
				}				
			}			
			suma=suma+a[maid];
			a[maid]=0;			
		}
		if(n%3==2){
			for(int i=1;i<=n;i++){
				if(a[i]>maxa){
					maxa=a[i];
					maid=i;
				}				
			}			
			suma=suma+a[maid];
			a[maid]=0;	
			for(int i=1;i<=n;i++){
				if(b[i]>maxb){
					maxb=b[i];
					mbid=i;
				}				
			}
			sumb=sumb+b[maid];
			b[maid]=0;		
		}
		cout<<suma+sumb+sumc;
					

		
	
	}
	return 0;
} 
