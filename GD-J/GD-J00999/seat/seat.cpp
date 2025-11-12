#include <bits/stdc++.h>
using namespace std;
int n[101];
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int l,r ;
	cin>>l>>r;
	
	for(int i=1  ; i<=l*r ; i++){
		cin>>n[i];
	}
	
	int xl=n[1];
	
	sort(n+1,n+l*r+1);
	
	int l1=1;
	int r1=1;
	
	int sum=l*r;
	
	bool k=true;
	

	while(true){
		if(n[sum]==xl){
			cout<<l1<<' '<<r1;
			break;
		}
		sum--;
		
		
		if(!k && r1>1){
			r1--;
			continue;
		}
		if(k && r1<r){
			r1++;
			continue;		
			
		}
		if(r1==r){
			l1++;
			k=false;
			continue; 
		}
 
		
		
		if(r1==1){
			l1++;
			k=true;
		}
		
		
		
	}
	return 0;
}
