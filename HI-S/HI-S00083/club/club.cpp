#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,a[100005][4],b[100005],pm[100005][4],strs[4],myd,cc; 
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t;
	for(int o=1;o<=t;o++){

		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];	
			}
			for(int j=1;j<=3;j++){
				pm[i][j]=j;
			}
		}
		
		for(int i=1;i<=n;i++){
			if(a[i][1]<a[i][2]){
				swap(a[i][1],a[i][2]);
				swap(pm[i][1],pm[i][2]);
			}
			else if(a[i][2]<a[i][3]){
				swap(a[i][3],a[i][2]);
				swap(pm[i][3],pm[i][2]);
			}
			else if(a[i][1]<a[i][2]){
				swap(a[i][1],a[i][2]);
				swap(pm[i][1],pm[i][2]);
			}	
		}
		
		for(int i=1;i<=n;i++){
			strs[pm[i][1]]++;
		} 
		for(int i=1;i<=n;i++){
			myd+=a[i][1];
		}
		
		bool flag=1;
		for(int i=1;i<=3;i++){
			if(strs[i]>n/2){
				flag=0;
				break;
				cc=i;
			}
		}
		if(flag==1) cout<<myd;
		else{
			myd=0;
			flag=1;
			int d=strs[cc]-n/2; 
			for(int i=1;i<=n;i++){
				b[i]=a[i][cc];
			}
			sort(b+1,b+n+1);
			for(int i=1;i<=n;i++){
				a[i][cc]=b[i];
			}
		}
	}
	
	return 0;
}

