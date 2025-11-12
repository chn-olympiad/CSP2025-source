#include<bits/stdc++.h>
using namespace std;
int t,n,s[10010][10010],a[100010],b[100010],c[100010],x,d[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int q=0;q<t;q++){
		cin>>n;
		memset(s,0,sizeof(s));
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}if(n<=200){
			for(int i=0;i<n;i++){
				for(int j=0;j<=i;j++){
					for(int k=0;k<=i-j;k++){
						if(i-j-k+1<=n/2)s[k][i-j-k+1]=max(s[k][i-j-k+1],s[k][i-j-k]+a[i]);
						if(k+1<=n/2)s[k+1][i-j-k]=max(s[k+1][i-j-k],s[k][i-j-k]+b[i]);
						if(j+1<=n/2)s[k][i-j-k]+=c[i];
					}
				}
			}
			for(int j=0;j<n;j++){
				for(int k=0;k<=n-j;k++){
					if(n-j-k<=n/2||k<=n/2||j<=n/2)x=max(x,s[k][n-j-k]);
				}
			}		
		}else{
			for(int i=0;i<n;i++){
				for(int j=0;j<=i;j++){
					if(i-j+1<=n/2)d[i-j+1]=max(d[i-j+1],d[i-j]+a[i]);
					if(j+1<=n/2)d[i-j]+=b[i];
				}
			}
			x=d[n/2];
		}
		cout<<x<<endl;x=0;
	}return 0;
}

