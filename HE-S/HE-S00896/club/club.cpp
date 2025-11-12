#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a;
	long long b;
	long long c;
	long long s;
	long long h;
};
node cl[102400];
int b[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t,n,sum=0,ma,h;
	cin>>t;
	while(t--){
		for(int i=1;i<=n;i++){
			cl[i].a=0;
			cl[i].b=0;
			cl[i].c=0;
			cl[i].s=0;
			cl[i].h=0;
		}
		memset(b,0,sizeof(b));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>cl[i].a>>cl[i].b>>cl[i].c;
		}
		ma=0;
		h=0;
		sum=0;
		for(int i=1;i<=n;i++){
			if(cl[i].a>cl[i].b){
				ma=cl[i].a;
				h=1;
			}else{
				ma=cl[i].b;
				h=2;
			}
			if(ma<cl[i].c){
				ma=cl[i].c;
				h=3;
			}
			if(b[h]+1>n/2){
				for(int j=1;j<=i-1;j++){
					if(cl[j].h==h){
						sum+=ma;
						sum-=cl[j].s;
						if(h==1){
							if(cl[j].b>=cl[j].c){
								b[2]++;	
								cl[j].h=2;
								sum+=cl[j].b;											
							}else{
								b[3]++;
								cl[j].h=3;
								sum+=cl[j].c;	
							}
						}
						if(h==2){
							if(cl[j].a>=cl[j].c){
								b[1]++;	
								cl[j].h=1;
								sum+=cl[j].a;						
							}else{
								b[3]++;
								cl[j].h=3;
								sum+=cl[j].c;	
							}
						}
						if(h==3){
							if(cl[j].a>=cl[j].b){
								b[1]++;
								cl[j].h=1;
								sum+=cl[j].a;						
							}else{
								b[2]++;
								cl[j].h=2;
								sum+=cl[j].b;	
							}
						}				
					}
				}																	
			}else{
				b[h]++;
				sum+=ma;
				cl[i].s=ma;		
				cl[i].h=h;			
			}		
		}
		cout<<sum<<endl;	
	}	
	return 0;
}
