#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","t",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,a[1000010][3],max=INT_MIN;
	cin>>n>>m>>k;
	int c=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=3;j++){
		    cin>>a[i][j];
		    c+=a[i][j];
		    if(a[i][j]>max){
		    	max==a[i][j];
			}
	    }
	}
	if((c-max)>max){
		cout<<(c-max)-max;
	}else{
		cout<<max-(c-max);
	}
	return 0;
} 

