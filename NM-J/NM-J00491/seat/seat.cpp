#include<bits/stdc++.h>
using namespace std;

struct p{
	int c;
	int nu;
}a[105];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x=0,s=0,t=0,flg=0;//n行mlie
	bool w=0;
	cin>>n>>m;
	for (int i=0;i<n*m;i++){
		cin>>a[i].c;
		a[i].nu=i;
	}
	for(int i=0;i<n*m-1;i++){
		for(int j=0;j<n*m-i-1;j++){
			if(a[j].c<a[j+1].c) swap(a[j],a[j+1]);
		}		
	}
	for(int i=0;i<m;i++){
		t=0;
		for(int j=x;t<n;){
			if(i%2==0) {
				x++;
				w=0;			
				}
			else {
				x--;			
				w=1;
				}
			j=x;		
			t++;
			if(t==m){
				if(i%2==0) {
				x++;
				}
				else {
				x--;			
				
				}				
			}			
			if(a[flg].nu==0){ 
				
				cout<<i+1<<' '<<j;	
				return 0;		
			}
			flg++;
			
		}
	}
	
	return 0;
} 
