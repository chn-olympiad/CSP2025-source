//准考证GZ-S00053 学校：都匀二中 名字：刘宇蒙 
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int t,n,x=1e5,k,m,d;
int a[MAXN][5];
int b[MAXN][5];
int s[5];
int ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int ct=1;ct<=t;ct++){
		cin>>n;
		d=n+1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int j=1;j<=3;j++){
			for(int i=1;i<=n;i++){
				if(b[i][j-1]||b[i][j-2]){
					if(s[j]==n/2){
						if(a[i][j]>x){
							ans+=a[i][j]-x;
							//cout<<ans<<" ";
							b[i][j]=1;
							cout<<i<<" "<<j<<" ";
							b[k][m]=0;
							continue;
						}
						else continue;
					}
					if(b[i][j-1]){
						if(a[i][j]>a[i][j-1]){
							b[i][j-1]=0;
							b[i][j]=1;
							cout<<i<<" "<<j<<" ";
							ans+=a[i][j]-a[i][j-1];
							s[j]++;
							d--;
						}
						else {
							if(!(j-2))continue;
							if(a[i][j]>a[i][j-2]){
								b[i][j-2]=0;
								b[i][j]=1;
											cout<<i<<" "<<j<<" ";
								ans+=a[i][j]-a[i][j-2];
								s[j]++;
							}						
						}
					}continue;
				}
				
				if(s[j]==n/2){
					if(a[i][j]>x){
						ans+=a[i][j]-x;
						//cout<<ans<<" ";
						b[i][j]=1;
							cout<<i<<" "<<j<<" ";
						b[k][m]=0;
						continue;
					}
					else continue;
				}
				if(d-1>0){
					if(x>a[i][j]){
						x=a[i][j];
						k=i;m=j;
					}
					ans+=a[i][j];
					b[i][j]=1;
					cout<<i<<" "<<j<<" ";
					s[j]++;
					d--;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
