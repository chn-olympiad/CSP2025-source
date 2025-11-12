#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,m[N],x[N],y,s,c[N],t,a[N],b[N],h,k[N],g,j;
struct no{
	long long a,b,c;
}d[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		for(int i=1;i<=1e5+7;i++){
			a[i]=b[i]=c[i]=0;
		}
		cin>>n;
		s=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]){
				m[i]=1;
				if(b[i]>c[i]){
					x[i]=2;
					k[i]=3;
				}
				else{
					x[i]=3;
					k[i]=2;
				}
			}
			else if(b[i]>=a[i]&&b[i]>=c[i]){
				m[i]=2;
				if(a[i]>=c[i]){
					x[i]=1;
					k[i]=3;
				}
				else{
					x[i]=3;
					k[i]=1;
				}
			}
			else{
				m[i]=c[i];
				if(b[i]>=a[i]){
					x[i]=2;
					k[i]=1;
				}
				else{
					x[i]=1;
					k[i]=2;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(m[i]==1){
				if(h==s){
					if(x[i]==2){
						if(g==s){
							y+=c[i];
							j++;
						}else{
							y+=b[i];
							g++;
						}
					}else{
						if(j==s){
							y+=b[i];
							g++;
						}else{
							y+=c[i];
							j++;
						}
					}
				}else{
					y+=a[i];
					h++;
				} 
			}else if(m[i]==2){
				if(g==s){
					if(x[i]==1){
						if(h==s){
							y+=c[i];
							j++;
						}else{
							y+=a[i];
							h++;
						} 
					}else{
						if(j==s){
							y+=a[i];
							h++;
						}else{
							y+=c[i];
							j++;
						}
					}
				}else{
					y+=b[i];
					g++;
				}
			}else{
				if(j==s){
					if(x[i]==2){
						if(g==s){
							y+=a[i];
							h++;
						}else{
							y+=b[i];
							g++;
						}
					}else{
						if(h==s){
							y+=b[i];
							g++;
						}else{
							y+=a[i];
							h++;
						}
					}
				}else{
					y+=c[i];
					j++;
				}
			}
		}
		cout<<y;
	}
	
	return 0;
}
