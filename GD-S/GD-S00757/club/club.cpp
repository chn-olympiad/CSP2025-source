#include<bits/stdc++.h>
using namespace std;
int a;
int b,c[100010],d[100010],e[100010],f[100010],tt1,tt2;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>a;
	while(a--){
		int cc=0,dd=0,ee=0;
		cin>>b;
		
		for(int i=1;i<=b;i++){
			cin>>c[i]>>d[i]>>e[i];
			if(d[i]!=0 or e[i]!=0)tt1=1;
			if(e[i]!=0)tt2=1;
			f[i]=c[i];
		
		}
		
		int ans=0;
		
	 	if(tt1==0){
	 		
	 		sort(f+1,f+b+1);
			int abb=b;
			
			while(abb!=b/2){
				ans+=c[abb];
				abb--;
			}	
			cout<<ans<<endl;
		}
		if(tt1==0){
			break;
	 	}
		
	
	
	 for(int i=1;i<=b;i++){
			if(c[i]>d[i] and c[i]>e[i] and cc<b/2){
				ans+=c[i];
				cc++;
				
			}else if(cc>b/2){
				if(d[i]>e[i] and dd<b/2){
					ans+=d[i];
					dd++;
				}else{
					ans+=e[i];
					ee++;
				}
				
			}
			if(d[i]>c[i] and d[i]>e[i] and dd<b/2){
				ans+=d[i];
				dd++;
				
			}else if(dd>b/2){
				if(c[i]>e[i] and cc<b/2){
					ans+=c[i];
					cc++;
				}else{
					ans+=e[i];
					ee++;
				}
				
			}
			if(e[i]>c[i] and e[i]>d[i] and ee<b/2){
				ans+=e[i];
				ee++;
				
			}else if(ee>b/2){
				if(d[i]>c[i] and dd<b/2){
					ans+=d[i];
					dd++;
				}else{
					ans+=c[i];
					cc++;
				}
				
			} 
			
		} 
		cout<<ans<<endl;
	}
	retuen 0;
}
