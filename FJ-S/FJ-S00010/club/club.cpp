#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		int q=n/2;
		int a[n+1],b[n+1],c[n+1];
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
		}
		int s=0,z=0,x=0;
		for(int j=1;j<=n;j++){
			if(a[j]>b[j]&&a[j]>c[j]){
				s++;
			}
			else if(b[j]>a[j]&&b[j]>c[j]){
				z++;
			}
			else if(c[j]>b[j]&&c[j]>a[j]){
				x++;
			}
		}
		if(s<=q&&z<=q&&x<=q){
			int p=0,l=0,k=0;
			for(int j=1;j<=n;j++){
				if(a[j]>b[j]&&a[j]>c[j]){
					p+=a[j];
				}
				else if(b[j]>a[j]&&b[j]>c[j]){
					l+=b[j];
				}
				else if(c[j]>b[j]&&c[j]>a[j]){
					k+=c[j];
				}
			}
			cout<<p+l+k<<endl;
		}
		else {
			long long p=0,l=0,k=0;
			for(int j=1;j<=n;j++){
				if(a[j]>b[j]&&a[j]>c[j]){
					p+=a[j];
				}
				else if(b[j]>a[j]&&b[j]>c[j]){
					l+=b[j];
				}
				else if(c[j]>b[j]&&c[j]>a[j]){
					k+=c[j];
				}
			}
			if(s>q){
				for(int j=1;j<=n;j++){
					for(int d=j+1;d<=n;d++){
						if(a[d]>a[j]){
							swap(a[d],a[j]);
							swap(b[d],b[j]);
							swap(c[d],c[j]);
						}
					}
				}
				int f[n+1],g[n+1];
				for(int j=1;j<=n;j++){
					f[j]=a[j]-b[j];
					g[j]=a[j]-c[j];
				}
				int s=0;
				for(int j=n;j>n/2;j--){
					if(s>=q){
						break;
					}
					int e=0;
					if(a[j]>b[j]&&a[j]>c[j]){
						for(int d=1;d<j;d++){
							if(a[d]>b[d]&&a[d]>c[d]){
								if(f[j]>f[d]&&g[j]>f[d]){
									l+=b[d];
									p-=a[d];
									e++;
									s++;
									break;
								}
								if(f[j]>g[d]&&g[j]>g[d]){
									k+=c[d];
									p-=a[d];
									e++;
									s++;
									break;
								}
							}
							
						}
						if(e==0){
							p-=a[j];
							if(b[j]>=c[j]){
								l+=b[j];
								s++;
							}
							else{
								k+=c[j];
								s++;
							}
						}
				}
					}	
					
				cout<<p+l+k<<endl;
			}
			else if(z>q){
				for(int j=1;j<=n;j++){
					for(int d=j+1;d<=n;d++){
						if(b[d]>b[j]){
							swap(b[d],b[j]);
							swap(a[d],a[j]);
							swap(c[d],c[j]);
						}
					}
				}
				for(int j=1;j<=n;j++){
				}
				int f[n+1],g[n+1];
				for(int j=1;j<=n;j++){
					f[j]=b[j]-a[j];
					g[j]=b[j]-c[j];
				}
				int s=0;
				for(int j=n;j>n/2;j--){
					if(s>=q){
						break;
					}
					int e=0;
					if(b[j]>a[j]&&b[j]>c[j]){
						for(int d=1;d<j;d++){
							if(b[j]>a[j]&&b[j]>c[j]){
								if(f[j]>f[d]&&g[j]>f[d]){
									p+=a[d];
									l-=b[d];
									e++;
									s++;
									break;
								}
								else if(f[j]>g[d]&&g[j]>g[d]){
									k+=c[d];
									l-=b[d];
									e++;
									s++;
									break;
								}
							}	
						}
						if(e==0){
							l-=b[j];
							if(a[j]>=c[j]){
								p+=a[j];
								l-=b[j];
								s++;
							}
							else{
								k+=c[j];
								l-=b[j];
								s++;
							}
						}
					}
				}
				cout<<p+l+k<<endl;
			}
			else if(x>q){
				for(int j=1;j<=n;j++){
					for(int d=j+1;d<=n;d++){
						if(c[d]>c[j]){
							swap(c[d],c[j]);
							swap(b[d],b[j]);
							swap(a[d],a[j]);
						}
					}
				}
				int f[n+1],g[n+1];
				for(int j=1;j<=n;j++){
					f[j]=c[j]-a[j];
					g[j]=c[j]-b[j];
				}
				s=0;
				for(int j=n;j>n/2;j--){
					if(s>=q){
						break;
					}
				int e=0;
					if(c[j]>b[j]&&c[j]>a[j]){
						for(int d=1;d<j;d++){
							if(c[j]>b[j]&&c[j]>a[j]){
								if(f[j]>f[d]&&g[j]>f[d]){
									p+=a[d];
									k-=c[d];
									e++;
									s++;
									break;
								}
								if(f[j]>g[d]&&g[j]>g[d]){
									l+=b[d];
									k-=c[d];
									e++;
									s++;
									break;
								}
							}		
						}
					}
					
				
					if(e==0){
						k-=c[j];
						if(a[j]>=b[j]){
							p+=a[j];
							s++;
						}
						else{
							l+=b[j];
							s++;
						}
					}
				}
				cout<<p+l+k<<endl;
			}
		}
		
	} 
	return 0;
} 
