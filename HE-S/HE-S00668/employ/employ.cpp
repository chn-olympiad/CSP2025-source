#include <bits/stdc++.h>
using namespace std;
int n,m,nx;
long long c[500],sum1,sum2,b[500],p[500],f;
string a[500];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	for(int i=0;i<n;i++){
		p[i]=i;
	}
	for(int i=0;i<n;i++){
		b[i]=p[i];
	}
	for(int i=0;i<n-1;i++){
		for(int g=0;g<n;g++){
			p[i]=b[i];
		}
		for(int j=i+1;j<n;j++){
			for(int d=0;d<n;d++){
				f=0;
				if(a[d]=="0"){
					nx++;
				}
				if(a[d]=="1"&&nx<c[p[f++]]){
					sum1++;
				}
				p[i]=p[j];
				p[j]=b[i];
			}
			if(sum1>=m){
				sum2++;
			}
		}
	}
	cout<<(sum2%998244353);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
