#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,h,y,k;
int a[1000][1000],id[1000][1000];
struct li{
	int x,y;
}d[1000];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i][i];
	}
	for(int j=1;j<n;j++){
	for(int i=1;i<=n-j;i++){
			if(a[i][i+1]!=0){
			  continue;	
			}
			else{
			a[i][i+j]=a[i][i+j-1]^a[i+j-1][i+j];
			a[i+j][i]=a[i][i+j];
			if(a[i][i+j]==k){
				id[i][i+j]=a[i][i+j];
				h++;
				d[h].x=i;
				d[h].y=i+j;
			}
			}
		}
	}
	for(int i=1;i<=h;i++){
		int l=0;
		for(int j=1;j<=h;j++){
			if(d[i].y>=d[j].x||d[i].x<=d[j].y){
			}
			else{
				l++;
				y=max(y,l);
			}
		}
		}
		cout<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
