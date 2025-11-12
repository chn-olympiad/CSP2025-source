#include<bits/stdc++.h>
using namespace std;
int n,k,a1,dm=0,su=0,tn;
bool a[200001][17],c[17],b[200001],s[17];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int m=0;
		cin>>a1;
		if(a1==k){
			b[i]=1;
			tn--;
			su++;
		}
		if(a1==0){
			for(int j=1;j<=dm;j++){
				a[i][j]=a[i-1][j];
			}
		}
		while(a1!=0){
			c[++m]=a1%2;
			if(a[i-1][m]!=c[m]){
				a[i][m]=1;
			}else{
				a[i][m]=0;
			}
			a1/=2;
		}
		if(m>dm){
			dm=m;
		}
		for(int j=m+1;j<=dm;j++){
			a[i][j]=a[i-1][j];
		}
	}
	int m=0;
	while(k!=0){
		s[++m]=k%2;
		k/=2;
	}
	for(int i=1;i<=n+1;i++){
		for(int j=0;j<=n-i;j++){
			for(int l=j+i;l<=n;l++){
				if(b[j]==0&&b[l]==0){
					bool f=0;
					for(int t=1;t<=dm;t++){
						if(a[j][t]==a[l][t]&&s[t]==1){
							f=1;
							break;
						}
						if(a[j][t]!=a[l][t]&&s[t]==0){
							f=1;
							break;
						}
					}
					if(f==0){
						for(int t=j;t<=l;t++){
							b[t]=1;
							tn--;
							su++;
						}
					}
				}
				if(tn<i){
					break;
				}
			}
			if(tn<i){
				break;
			}
		}
		if(tn<i){
			break;
		}
	}
	cout<<su;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
