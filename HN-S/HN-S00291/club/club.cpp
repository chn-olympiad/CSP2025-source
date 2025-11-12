#include<bits/stdc++.h>
using namespace std;
int t,tt,n;
int a[100005],b[100005],c[100005];
int m[300005];
int s[300005];
int d[300005];
bool k[20005];
int zb[5];
int l=0;
int sam=0,sum=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		l=1;
		sum=0;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
			m[l]=a[j];
			m[l+1]=b[j];
			m[l+2]=c[j];
			s[l]=s[l+1]=s[l+2]=j;
			d[l]=1;
			d[l+1]=2;
			d[l+2]=3;
			l+=3;
		}
		for(int x=1;x<=n*3;x++){
			for(int y=x;y>=2;y--){
				if(m[y]>=m[y-1]){
					tt=m[y-1];
					m[y-1]=m[y];
					m[y]=tt;
					tt=s[y-1];
					s[y-1]=s[y];
					s[y]=tt;
					tt=d[y-1];
					d[y-1]=d[y];
					d[y]=tt;
				}
			}
		}
		for(int i=1;i<=n*3;i++){
			for(int j=1;j<=n*3;j++){
				for(int z=i;z<=n*3;z++){
					if(!k[s[z]]&&zb[d[z]]+1<=n/2){
						sam+=m[z];
						k[s[z]]=1;
						zb[d[z]]++;
					}
				}
			}
			sum=max(sum,sam);
			sam=0;
			for(int i=1;i<=n*3;i++){
				k[s[i]]=0;
				zb[d[i]]=0;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
} 
//Ren5Jie4Di4Ling5%
