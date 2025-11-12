#include<bits/stdc++.h>
using namespace std;
struct d{
	int p,c;
};
bool cmp(d a,d b){
	return a.c>b.c;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;cin>>m>>n;
	d a[200];int s=m*n;
	for(int i=1;i<=s;i++){
	    cin>>a[i].c;a[i].p=i;
	}
	sort(a+1,a+s+1,cmp);
	
	for(int i=1;i<=s;i++){
		if(a[i].p==1){
			int b[11][11],j=1,x=1,y=1;
			while(j<i){
				for(int k=1;k<n;k++){
					if(j>=i)break;
					
					j++;y++;
					
				}
				if(j>=i)break;
			
				x++;j++;
				for(int k=1;k<n;k++){
					if(j>=i)break;
					
					j++;y--;
				}
				if(j>=i)break;
				x++;j++;
			}
			cout<<x<<' '<<y;
			break;
		}
	}
	return 0;
}