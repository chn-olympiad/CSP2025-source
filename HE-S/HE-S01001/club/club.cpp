#include <bits/stdc++.h>
using namespace std;
int T,n;
int a[100010][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){	
      cin>>n;
      for(int i=1;i<=n;i++){
      	for(int j=1;j<=3;j++){
      		cin>>a[i][j];
		  }
	  }
	  if(a[1][2]==0&&a[1][3]==0){
	  	int aa[100010]={};
	    for(int i=1;i<=n;i++){ 
	    	aa[i]=a[i][1];
		}
		sort(aa+1,aa+1+n);
		int jsq=0;
		for(int i=n;i>n/2;i--){
			jsq+=aa[i];
		}
		cout<<jsq<<endl;
		continue;
	  } 
	}
	
	return 0;
}
