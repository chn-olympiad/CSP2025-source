#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int T,n,ans=0,a[N][3]={},ai[3]={},b[N][3]={};
int Findmaxi(int x,int y,int z){
	if(x>=y&&x>=z) return 0;
	else if(y>=x&&y>=z) return 1;
	else return 2;
}
int Findmini(int x,int y,int z){
	if(x<=y&&x<=z) return 0;
	else if(y<=x&&y<=z) return 1;
	else return 2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0,ai[0]=0,ai[1]=0,ai[2]=0;
		cin>>n;
		for(int i=0;i<N;i++){
			for(int j=0;j<3;j++){
				a[i][j]=0;
			}
		}
		int x[3]={};
		for(int i=1;i<=n;i++){
			cin>>x[0]>>x[1]>>x[2];
			int m1=Findmaxi(x[0],x[1],x[2]),m2=Findmini(x[0],x[1],x[2]);
			ans+=x[m1];
			
			a[ai[m1]++][m1]=x[3-m1-m2]-x[m1];
		}
		
	
		int c,bol=1;
		for(int i=0;i<3;i++){
			if(ai[i]>n/2){
				bol=0;
				c=i;
			}
		}
		
		if(bol){
			cout<<ans<<endl;
			continue;
		}
		
		int s=ai[c]-n/2;
		
		for(int i=0;i<s;i++){
			int maxx=a[0][c],maxi=-1;
			for(int j=0;j<ai[c];j++){
				if(maxx<a[j][c]){
					maxx=a[j][c];
					maxi=j;
				}
			}
			ans+=maxx;
			a[maxi][c]=0;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
