#include<bits/stdc++.h>
using namespace std;
struct myd{
	int ai1,ai2,ai3;
};
struct jr{
	int m1,m2;
};
bool cmp(jr a,jr b){
	return a.m1>b.m1;
}
int t,n;
jr m[4];
int main(){
    freopen("club","r",stdin);
    freopen("club","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
    	cin>>n;
		myd b[n];
    	int M=0,a[4]={0,0,0,0};
    	for(int j=1;j<=n;j++){
    		for(int l=1;l<=3;l++){
				cin>>b[j].ai1;
	    		m[l].m1=b[j].ai1;
	    		m[l].m2=l; 			
			}
    		sort(m+1,m+4,cmp);
			if(a[m[1].m2]*2<n){
				a[m[1].m2]++;
				M+=m[1].m1;
			}else if(M<1 && a[m[2].m2]*2<n){
				a[m[2].m2]++;
				M+=m[2].m1;
			}else{
				a[m[3].m2]++; 
				M+=m[3].m1;
			}
		}		
		cout<<M<<endl;
	}
	return 0;
}

