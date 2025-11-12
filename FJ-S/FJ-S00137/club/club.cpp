#include<bits/stdc++.h>
using namespace std;
int t,n,a[3][100005],ans,num[5],e[100005],f[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	for(int i=0;i<t;i++){
    	cin>>n;
    	for(int j=0;j<n;j++){
		for(int k=0;k<3;k++) cin>>a[k][j];
    	}
    	for(int y=0;y<n;y++){
    		e[y]=a[0][y];
     		sort(e,e+n,greater<int>());
    		f[y]=a[1][y];
    		sort(f,f+n,greater<int>());
    	}
    	for(int z=0;z<n/2;z++){
    		ans+=e[z];
    		ans+=f[z];
		}
	    num[i]=ans;
	    ans=0;
	}
	for(int x=0;x<t;x++){
    		cout<<num[x]<<endl;
    }
	return 0;
}
