#include<bits/stdc++.h>
using namespace std;
long long t,n,uf=0,us=0,ut=0,sum=0;
struct node{
	long long fir,sec,tir,ma=0,md;
}a[1000010];
bool cmp(node x,node y){
	return x.ma>y.ma;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j){
				if(j==1){
					cin>>a[i].fir;
					a[i].ma=max(a[i].ma,a[i].fir);
					a[i].md=j;					
				}else if(j==2){
					cin>>a[i].sec;
					a[i].ma=max(a[i].ma,a[i].sec);
					if(a[i].ma==a[i].sec){
						a[i].md=j;					
					}
				}else if(j==3){
					cin>>a[i].tir;
					a[i].ma=max(a[i].ma,a[i].tir);
					if(a[i].ma==a[i].tir){
						a[i].md=j;					
					}
				}
			}
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;++i){
			if(a[i].md==1){
				if(uf<(n/2)){
					sum+=a[i].ma;
					uf+=1;					
				}else if(a[i].sec>=a[i].tir){
					sum+=a[i].sec;
					us+=1;	
				}else{
					sum+=a[i].tir;
					ut+=1;
				}
			}else if(a[i].md==2){
				if(us<(n/2)){
					sum+=a[i].ma;
					us+=1;					
				}else if(a[i].fir>=a[i].tir){
					sum+=a[i].fir;
					uf+=1;	
				}else{
					sum+=a[i].tir;
					ut+=1;
				}
			}else if(a[i].md==3){
				if(ut<(n/2)){
					sum+=a[i].ma;
					ut+=1;					
				}else if(a[i].fir>=a[i].sec){
					sum+=a[i].fir;
					uf+=1;	
				}else{
					sum+=a[i].sec;
					us+=1;
				}
			}
			a[i].ma=0;
			a[i].md=0;
		}
		us=0;
		uf=0;
		ut=0;
		cout<<sum<<endl;
		sum=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 