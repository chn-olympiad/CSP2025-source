#include<bits/stdc++.h>
using namespace std;
int t,n,a[4000],b[4000],c[4000],s,q[100005],w[100005],e[100005],f[10][10],m;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t>>n;
	while(t--){
		int maxa=-9999999;
		if(n==2){
				cin>>q[0]>>q[1]>>q[2];
				cin>>q[3]>>q[4]>>q[5];
				for(int i=0;i<=2;i++){
					for(int j=3;j<=5;j++){
						if(i==0&&j==3){
						}else{
							if(i==1&&j==4){
								}else{
									if(i==2&&j==5){
									}else{
										f[i][j]=q[i]+q[j];
										}
									}
							}			
						}
				}
				for(int i=0;i<=2;i++){
					for(int j=3;j<=5;j++){
							maxa=max(maxa,f[i][j]);
						}
				}
				cout<<maxa;
		}else{
			for(int i=0;i<n;i++){
			cin>>q[i]>>w[i]>>e[i];
			s=max(q[i],max(w[i],e[i]));
			if(a[n/2-1]==0&&b[n/2-1]==0&&c[n/2-1]==0){
				if(s==q[i]){
					a[i]=q[i];
				}else{
					if(s==w[i]){
						b[i]=w[i];
					}else{
						if(s==e[i]){
							c[i]=e[i];
						}
					}
				}
			
			}else{
		sort(a,a+i+1);
		sort(b,b+i+1);
		sort(c,c+i+1);
				if(s==q[i]){
					a[0]=q[i];
				}else{
					if(w[i]>e[i]&&s>w[0]){
						b[0]=w[i];
						}else{
							c[0]=e[i];
					}
				}
			}
		}
		s=0;
		m=0;
		sort(a,a+n);
		sort(b,b+n);
		sort(c,c+n);	
		for(int i=n-1;i>=n/2;i--){
			m+=a[i]+b[i]+c[i];
		}
		cout<<m<<endl;
		}
		for(int i=0;i<n;i++){
			a[i]=0;b[i]=0;c[i]=0;q[i]=0;w[i]=0;e[i]=0;
		}
	}
	
	return 0;
}
