#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL n,t,all[10010][3];
LL anum = 0,bnum = 0,cnum = 0,ans = 0;
LL a[10010],b[10010],c[10010];

int main(){
	
	freopen("club4.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	
	for(int x=0;x<t;x++){
		
		cin>>n;
		
		anum = 0;
		bnum = 0;
		cnum = 0;
		ans = 0;
		
		for(int i=0;i<n;i++){
			
			cin>>all[i][0]>>all[i][1]>>all[i][2];
			LL n1 = all[i][0];
			LL n2 = all[i][1];
			LL n3 = all[i][2];
			
			if(n1>=n2&&n1>=n3){
				
				LL db,dc;
				db = n1-n2;
				dc = n1-n3;
				if(db>=dc)a[anum++] = dc;
				else a[anum++] = db;
				
				ans+=n1;
			}//ȥ1 
			else if(n2>=n3&&n2>=n1){
				
				LL da,dc;
				da = n2-n1;
				dc = n2-n3;
				if(da>=dc)b[bnum++] = dc;
				else b[bnum++] = da;
				
				ans+=n2;
			}//ȥ2
			else{
				LL da,db;
				da = n3-n1;
				db = n3-n2;
				if(db>=da)c[cnum++] = da;
				else c[cnum++] = db;
				
				ans+=n3;
			}//ȥ3 
			
		}
		if(anum>n/2){
			sort(a,a+anum);
			for(int i=0;i<(anum-n/2);i++)ans -= a[i];
		}
		else if(bnum>n/2){
			sort(b,b+bnum);
			for(int i=0;i<(bnum-n/2);i++)ans -= b[i];
		}
		else if(cnum>n/2){
			sort(c,c+cnum);
			for(int i=0;i<(cnum-n/2);i++)ans -= c[i];
		}
		
		cout<<ans<<'\n';
		
	}
	
	return 0;
	
}
