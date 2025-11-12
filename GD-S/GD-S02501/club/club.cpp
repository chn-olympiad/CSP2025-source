#include<bits/stdc++.h>
using namespace std;

const int N=100010;
int x[N],y[N],z[N],a[N]; 
int T,n,maxn,cnt;
bool fz,fx;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		memset(z,0,sizeof(z));
		cin>>n;
		maxn=n/2; 
		fz=fx=0;
		cnt=0;
		for(int i=1;i<=n;i++) {
			cin>>x[i]>>y[i]>>z[i];
			if(x[i]!=0) {
				fx=1;
			}
			if(z[i]!=0) {
				fz=1;
			}
		} 
		if(fz==0&&fx==0) {
			sort(y+1,y+n+1);
			for(int i=n;i>=maxn;i--) {
//				cout<<y[i]<<' ';
				cnt+=y[i];
			}
			cout<<cnt<<endl; 
		}
		else {
			int tx=0,ty=0,tz=0;
			for(int i=1;i<=n;i++) {
				if(x[i]>max(y[i],z[i])) {
					if(tx<maxn) {
						tx++;
						cnt+=x[i];				
					}

				}
				if(y[i]>max(x[i],z[i])) {
					if(ty<maxn) {
						ty++;
						cnt+=y[i];				
					}
				}
				if(z[i]>max(y[i],x[i])) {
					if(tz<maxn) {
						tz++;
						cnt+=z[i];				
					}					
				}
			} 
			cout<<cnt<<endl;
		}
//		else {
//			if(x>max(y,z)) {
//				sort(a+1,a+n+1);
//			}
//			for(int i=1;i<=n;i++) {
//				
//			}		
//		} 

	}
	return 0;
	//Ren5Jie4Di4Ling5%
}
