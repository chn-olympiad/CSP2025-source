#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	x>y;
}
long long n[6],t,a[10005][6],z[10005],x[6],sum=0,x1[10005],x2[10005],x3[10005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i];
		for(int j=1;j<=n[i];j++){
			for(int k=1;k<=3;k++){
				cin>>a[j][k];
			}
		}
	}
	for(int k=1;k<=t;k++){
		sum=0;
		for(int i=1;i<=n[k];i++){
		    if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
		    	x[1]++;
		    	z[i]=a[i][1];
		    	x1[i]=a[i][1];
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
		    	x[2]++;
		    	z[i]=a[i][2];
		    	x2[i]=a[i][2];
			}
			else if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1]){
		    	x[3]++;
		    	z[i]=a[i][3];
		    	x3[i]=a[i][3];
			}
	    }
	    sort(x1+1,x1+1+n[k]);
	    sort(x1+1,x1+1+n[k],cmp);
	    sort(x2+1,x2+1+n[k]);
	    sort(x2+1,x2+1+n[k],cmp);
	    sort(x3+1,x3+1+n[k]);
	    sort(x3+1,x3+1+n[k],cmp);
	    for(int i=1;i<=n[k];i++){
		    if(x[1]<=n[k]/2&&x[2]<=n[k]/2&&x[3]<=n[k]/2){
			    sum+=z[i];
		    }
	    }
	    if(x[1]>n[k]/2){
	    	for(int i=1;i<=n[k]/2;i++){
	    		sum+=x1[i];
	    		sum+=max(x2[i],x3[i]);
			}
		}
		if(x[2]>n[k]/2){
	    	for(int i=1;i<=n[k]/2;i++){
	    		sum+=x2[i];
	    		sum+=max(x1[i],x3[i]);
			}
		}
		if(x[3]>n[k]/2){
	    	for(int i=1;i<=n[k]/2;i++){
	    		sum+=x3[i];
	    		sum+=max(x1[i],x2[i]);
			}
		}
	    cout<<sum<<endl;
	    for(int i=1;i<=n[k];i++){
	    	cout<<x1[i]<<" "<<x2[i]<<" "<<x3[i]<<endl;
		}
	}
	return 0;
}
