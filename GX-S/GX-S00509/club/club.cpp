#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=1005;
int a[MAXN];
int ans=0;
int satisfy[MAXN];
int d[3];

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int n;
	int t;
	cin>>t;
	for(  int h=1 ; h<=t ; h++  ){
		cin>>n;
		if( ( n%2 )==0 ){
			for(  int i=0 ; i<=n ; i++  ){
				for(  int j=1 ; j<=3 ; j++  ){
					cin >> a[j];	
					if( a[1] > a[2] && a[1] > a[3] )
						d[1]++;
					if( a[2] > a[1] && a[2] > a[3] )
						d[2]++;
					if( a[3] > a[2] && a[3] > a[1] )
						d[3]++;
					
		
			if( d[1] > (n/2) ){
				d[1]--;
				if( a[2] > a[3] ){
					d[2]++;}
				else{
					d[3]++;}
				}
				
				if( d[2] > (n/2) ){
				d[2]--;
				if( a[1] > a[3] ){
					d[1]++;}
				else{
					d[3]++;}
				}
				
				
				if( d[3] > (n/2) ){
				d[3]--;
				if( a[1] > a[2] ){
					d[1]++;}
				else{
					d[2]++;}
				}
				
				satisfy[h]+=a[j];
				
				}
			}
				cout << satisfy[h];
		}
		
		if(n==1){
			for(  int i=1 ; i<=3 ; i++  )
				cin>>a[1]>>a[2]>>a[3];
			if(  a[1] > a[2] && a[1] > a[3]  )
				d[1]++;
			if(  a[2] > a[1] && a[2] > a[3]  )
				d[2]++;
			if(  a[3] > a[1] && a[3] > a[2]  )
				d[3]++;
			
			
			if( d[3] > (n/2) ){
				d[3]--;
				if( a[1] > a[2] ){
					d[1]++;}
				else{
					d[2]++;}
				}
				
				satisfy[h]=a[1]+a[2]+a[3];
				cout<<satisfy[h];
		}
	}
	
	
return 0;
}
