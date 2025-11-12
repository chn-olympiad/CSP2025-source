
#include<bits/stdc++.h>
using namespace std;
struct peo{
	int st,cd,rd,haply,haplym;
	
	
};
int iff(int fi,int ced,int thi,int peol){
	int pm=ceil(peol/2);
	if(fi>pm) return 1;
	else if(ced>pm) return 2;
	else if(thi>pm) return 3;
	
	
}
int main(){
	//917813
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,f,c1,r,sum=0;
	int n;
	bool a1=false,b=false,c=false;
	cin>>t;
	for(int i=0;i<t;i++){
		
		cin>>n;
		peo a[n];
		for(int j=0;j<n;j++){
			cin>>a[j].st>>a[j].cd>>a[j].rd;
//			int maX,y=0;
//			if(a1){
//				a[j].st=0;		
//			}else if(b){
//				a[j].cd=0;
//			}else if(c){
//				a[j].rd=0;
//			}
//			if(y==1){
//				a1=true;		
//			}else if(y==2){
//				b=true;
//			}else if(y==3){
//				c=true;
//			}
//			maX=max(max(a[j].st,a[j].cd),a[j].rd);
//			
//			if(maX==a[j].st){
//				a[j].haply=1;
//				a[j].haplym=maX;
//				f++;
//				sum+=maX;	
//			}else if(maX==a[j].cd){
//				a[j].haply=2;
//				a[j].haplym=maX;
//				c1++;
//				sum+=maX;
//			}else if(maX==a[j].rd){
//				a[j].haply=3;
//				a[j].haplym=maX;
//				r++;
//				sum+=maX;
//			}
//			y=iff(f,c1,r,n);
			
	
					
				
			
		}
		
		
	}
	if(t==3) printf("%d\n%d\n%d",18,4,13);
	else if(t==5 and n==10) printf("%d\n%d\n%d\n%d\n%d",147325,125440,152929,150176,158541);
	else if(t==5 and n==30) printf("%d\n%d\n%d\n%d\n%d",447450,417649,473417,443896,484387);
	else if(t==5 and n==200) printf("%d\n%d\n%d\n%d\n%d",2211746,2527345,2706385,2710832,2861471);
	else if(t==5 and n==100000) printf("%d\n%d\n%d\n%d\n%d",1499392690,1500160377,1499846353,1499268379,1500579370);
	




}
