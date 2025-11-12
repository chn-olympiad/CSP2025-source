#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("club.in","r",stdin); 
	freopen("club.out","t",stdout); 
	int n;
	int w,y;
	int ans;
	int a[300][300];	
	cin>>w;
	for(int i=0;i<=w;i++){
	    cin>>n;
		for(int y=0;y<=n;y++){
			for(int i=0;i<=2;i++){
				cin>>a[y][i];
			}
		} 
		for(int r=0;r<=2;r++){
    	sort(a[0][r],a[y][r]+1);
	}
	    for(int i=0;i<=n,i++ ){
	    	int e=0,p=0;
	    	ans=ans+a[e][p];
	    	if(p==3) p=0;
		}
		cout<<ans;
	        
	} 
    
}
