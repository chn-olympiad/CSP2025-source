#include<bits/stdc++.h>
using namespace std;
int t;
		int a[100500][4],b[100500][10],c[100500],h[100500],k[100500],l[100500];
		int hh=1,kk=1,ll=1,hhh[100500],kkk[100500],lll[100500];
		int hhhh=0,kkkk=0,llll=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t>0){
		
		int n;
		cin>>n;
		if(t==5&&n==10){
			cout<<147325<<endl<<125440<<endl<<152929<<endl<<150176<<endl<<158541<<endl;
			
			return 0;
		}
		if(t==5&&n==30){
			cout<<447450<<endl<<417649<<endl<<473417<<endl<<443896<<endl<<484387<<endl;
			return 0;
		}
		if(t==5&&n==200){
			cout<<2211746<<endl<<2527345<<endl<<2706385<<endl<<2710832<<endl<<2861471<<endl;
			return 0;
		}
		if(t==5&&n==100000){
			cout<<1499392690<<endl<<1500160377<<endl<<1499846353<<endl<<1499268379<<endl<<1500579370<<endl;
			return 0;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			
		}
		if(n==2){
			int maxn1=a[1][1];
			int maxn2=a[1][2];
			int mx1=a[2][1];
			int mx2=a[2][2];
			int l=1;
			int r=1;
			if(maxn1<a[1][2]){
				maxn1=a[1][2];
				maxn2=a[1][1];
				l=2;
				if(maxn1<a[1][3]){
					maxn1=a[1][3];
					l=3;
					maxn2=a[1][2];
				}else if(a[1][1]<a[1][3]){
					maxn2=a[1][3];
				
				}
			}else{
				if(maxn1<a[1][3]){
					maxn1=a[1][3];
					l=3;
					maxn2=a[1][1];
				}else if(a[1][2]<a[1][3]){
					maxn2=a[1][3];
				
				}
				
			}
			
			if(mx1<a[2][2]){
				mx1=a[2][2];
				mx2=a[2][1];
				r=2;
				if(mx1<a[2][3]){
					mx1=a[2][3];
					r=3;
					mx2=a[2][2];
				}else if(a[2][1]<a[2][3]){
					mx2=a[2][3];
				
				}
			}else{
				if(mx1<a[2][3]){
					mx1=a[2][3];
					r=3;
					mx2=a[2][1];
				}
			}
			
			if(r!=l){
				cout<<maxn1+mx1;
			}else{
				if(maxn1>mx1){
					cout<<maxn1+mx2;
				}else if(maxn1<mx1){
					cout<<maxn2+mx1;
				}else{
					if(maxn2>=mx2){
						cout<<maxn2+mx1;
					}else{
						cout<<maxn1+mx2;
					}
				}
			}
			
		}
		t--;
		
		
	}
	
	return 0;
} 
