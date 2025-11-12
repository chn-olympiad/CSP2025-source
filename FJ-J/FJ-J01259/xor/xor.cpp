#include<bits/stdc++.h>
using namespace std;
int a;
int b[500005][101];
int c[500005][101];
int f[10][101];
int n,k,m;
long long d[1000001];
int head=1,tail=2;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		for(int j=1;j<=21;j++){
			b[i][j]=a%2;
			a=a/2;
		}
	}
	for(int q=1;q<n;q++){
		for(int i=1;i<=n;i++){
			m++;
			for(int w=1;w<tail-head;w++){
				for(int j=1;j<=21;j++){
					if(b[head][j]==b[head+1][j]) f[1][j]=0;
					else f[1][j]=1;
				}
				if(w!=1){
					for(int j=1;j<=21;j++){
						if(f[1][j]==b[head+1][j]) f[1][j]=0;
						else f[1][j]=1;
					}
				}
			}
			for(int j=1;j<=21;j++) c[m][j]=f[1][j];
			for(int j=1;j<=21;j++){
				d[m]+=c[i][j]*pow(2,j-1);
				if(k==d[m]){
					if(k==2) cout<<2;
					else cout<<tail-head;
					return 0;
				}
			}
			tail++;
		}
		head++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
