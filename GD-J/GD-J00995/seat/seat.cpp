#include<bits/stdc++.h>
using namespace std;
int chengji[105],kc[15][15],n,m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;//n––m¡– 
	for(int i=0;i<n*m;i++){
		cin>>chengji[i];
	}
	int t=0,a1=chengji[0],x,y;
	sort(chengji,chengji+n*m,cmp);
		for(int j=1;j<=m;j++){
			for(int i=1;i<=n;i++){	
				if(chengji[t]==a1){
					x=j,y=i;
					if(j%2==0){
						y=n-i+1;
					}
					cout<<x<<' '<<y;
				//	return 0;
				}		t++;
			}
			
		
	}
	return 0;
}
