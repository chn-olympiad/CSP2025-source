#include<bits/stdc++.h>
using namespace std;
int n,t,a[100010][4],dp[100010],p[4],k[2],minx[4],mink[4];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		minx[1]=INT_MAX;
		minx[2]=INT_MAX;
		minx[3]=INT_MAX;
		for(int i=1;i<=n;i++){
		    int maxx=0; 
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>maxx){
					maxx=a[i][j];
					k[i%2]=j;
				}
			}
			
			if(i%2==0){
				dp[i]=dp[i-2];
				dp[i]+=a[i][k[0]];
				if(minx[k[0]]>a[i][k[0]]){
					minx[k[0]]=a[i][k[0]];
					mink[k[0]]=i;
				}
				else if(minx[k[0]]=a[i][k[0]]){
					if(max(a[i][(k[0]+1)%3],a[i][(k[0]+2)%3])>max(a[mink[k[0]]][(k[0]+1)%3],a[mink[k[0]]][(k[0]+2)%3])) mink[k[0]]=i;
				}
				if(k[0]!=k[1]){
					dp[i]+=a[i-1][k[1]];
					if(minx[k[1]]>a[i-1][k[1]]){
						minx[k[1]]=a[i-1][k[1]];
						mink[k[1]]=i-1;
					}
					else if(minx[k[1]]=a[i-1][k[1]]){
						if(max(a[i-1][(k[1]+1)%3],a[i-1][(k[1]+2)%3])>max(a[mink[k[1]]][(k[1]+1)%3],a[mink[k[1]]][(k[1]+2)%3])) mink[k[1]]=i-1;
					}
				}
				else{
					if(minx[k[0]]>a[i-1][k[0]]){
						minx[k[0]]=a[i-1][k[0]];
						mink[k[0]]=i-1;
					}
					else if(minx[k[0]]=a[i-1][k[0]]){
						if(max(a[i-1][(k[0]+1)%3],a[i-1][(k[0]+2)%3])>max(a[mink[k[0]]][(k[0]+1)%3],a[mink[k[0]]][(k[0]+2)%3])) mink[k[0]]=i-1;
					}
					dp[i]+=a[i-1][k[0]];
					dp[i]-=a[mink[k[0]]][k[0]];
					dp[i]+=max(a[mink[k[0]]][(k[0]+1)%3],a[mink[k[0]]][(k[0]+2)%3]);
				}
				
			}
		}
		cout<<dp[n];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 