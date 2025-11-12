#include<bits/stdc++.h>
using namespace std;
long long T,n,b[100010][5],l,as,bs,cs;
struct z{
	long long a,b,c;
}a[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(long long q=1;q<=T;q++){
		cin>>n;
		for(long long i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		l=n/2;
		as=0,bs=0,cs=0;
		for(long long i=1;i<=n+1;i++){
			long long b1=0,b2=0;
			for(long long j=1;j<=3;j++){
				if(j==b1||j==b2){
					continue;
				}
				long long a1;
				if(j==1){
					a1=a[i].a;
					as++;
				}
				else if(j==2){
					a1=a[i].b;
					bs++;
				}
				else{
					a1=a[i].c;
					cs++;
				}
				if(as>l){
					as--;
					b[i][j]=b[i][j-1];
					j--;
					if(!b1){
						b2=1;
					}
					else{
						b1=1;
					}
				}
				else if(bs>l){
					bs--;
					b[i][j]=b[i][j-1];
					j--;
					if(!b1){
						b2=2;
					}
					else{
						b1=2;
					}
				}
				else if(cs>l){
					cs--;
					b[i][j]=b[i][j-1];
					j--;
					if(!b1){
						b2=3;
					}
					else{
						b1=3;
					}
				}
				b[i][j]=max(b[i][j-1],max(b[i-1][1],max(b[i-1][2],b[i-1][3]))+a1);
			}
			cout<<max(b[i][1],max(b[i][2],b[i][3]))-max(b[i-1][1],max(b[i-1][2],b[i-1][3]))<<' ';
		}
		cout<<max(b[n][1],max(b[n][2],b[n][3]))<<"\n";
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=3;j++){
				b[i][j]=0;
			}
		}
	}
	return 0;
}

