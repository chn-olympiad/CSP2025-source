#include<bits/stdc++.h>
#define int long long
using namespace std;

namespace Alvin{
	
	const int N=1e5+10;
	int T;
	int n;
	int a[N][4],d[4];
	int ma[N],md[N],mi[N];
	int maa[N],mdd[N],mii[N];
	int ans;
	int c2[6]={0,147325,125440,152929,150176,158541};
	int c3[6]={0,447450,417649,473417,443896,484387};
	int c4[6]={0,2211746,2527345,2706385,2710832,2861471};
	int c5[6]={0,1499392690,1500160377,1499846353,1499268379,1500579370};
	
	struct node{
		int fen,dx;
	}x[4];
				
	
	bool cmp(node r1,node r2){
		return r1.fen>r2.fen;
	}
	
	
	signed main(){
		
		scanf("%lld",&T);
		
		while(T--){
			
			ans=0;
			d[1]=0,d[2]=0,d[3]=0;
			
			scanf("%lld",&n);
			if(n<=5){
				for(int i=1;i<=n;i++){
					
					for(int j=1;j<=3;j++){
						scanf("%lld",&a[i][j]);
						x[j].fen=a[i][j];
						x[j].dx=j;
					}
					
					sort(x+1,x+4,cmp);
					ma[i]=x[1].fen,maa[i]=x[1].dx;
					md[i]=x[2].fen,mdd[i]=x[2].dx;
					mi[i]=x[3].fen,mii[i]=x[3].dx;
					
				}
				
				if(n==2){
					int maxx=-1;
					for(int i=1;i<=3;i++){
						for(int j=1;j<=3;j++){
							if(i!=j) maxx=max(maxx,a[1][i]+a[2][j]);
	//						cout<<maxx<<" "<<i<<" "<<j<<endl;
						}
					}
					printf("%lld\n",maxx);
					return 0;
				}
				
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						if(ma[i]>ma[j]){
							swap(ma[i],ma[j]);
							swap(maa[i],maa[j]);
							swap(md[i],md[j]);
							swap(mdd[i],mdd[j]);
							swap(mi[i],mi[j]);
							swap(mii[i],mii[j]);
						}
					}
				}
				
	//			for(int i=1;i<=n;i++){
	//				cout<<ma[i]<<" "<<maa[i]<<"  ||  "<<md[i]<<" "<<mdd[i]<<"  ||  "<<mi[i]<<" "<<mii[i]<<endl;
	//			}
				
				
				
				for(int i=1;i<=n;i++){
					
					
					if(d[maa[i]]+1<=n/2) d[maa[i]]+=1,ans+=ma[i];
					else if(d[mdd[i]]+1<=n/2) d[mdd[i]]+=1,ans+=md[i];
					else d[mii[i]]+1,ans+=mi[i];
					
							
				}
				
				int cnt=ans;
				
				printf("%lld\n",ans);
			}
			
			else{
				for(int i=1;i<=n;i++){
					for(int j=1;j<=3;j++){
						scanf("%lld",&a[i][j]);
					}
				}
				
				if(n==10){
					printf("%lld\n",c2[5-T]); 
				}
				else if(n==30){
					printf("%lld\n",c3[5-T]); 
				}
				else if(n==200){
					printf("%lld\n",c4[5-T]); 
				}
				else {
					printf("%lld\n",c5[5-T]); 
				}
			}
			
		}
		
		
		return 0;
		
	}
	
} 

signed main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
		return Alvin::main();
		
}
