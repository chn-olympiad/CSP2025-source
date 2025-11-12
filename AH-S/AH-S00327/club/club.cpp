#include<bits/stdc++.h>
using namespace std;
long long n,w[3][100005],m,m1,m2,v[3][100005],x[3][100005],t,p;
int main(){
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		p=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>w[0][i]>>v[0][i]>>x[0][i];
			w[1][i]=v[1][i]=x[1][i]=i;
		}
		m1=m2=m=n/2;
		sort(w[0]+1,w[0]+n+1);
		sort(v[0]+1,v[0]+n+1);
		sort(x[0]+1,x[0]+n+1);
		for(int i=n;i>n-m;i++){
			p+=w[0][i];
			w[2][i]=v[2][w[1][i]]=x[2][w[1][i]]=1;
		}
		for(int i=n;i>n-m1;i++){
			if(v[2][i]==1){
				if(v[0][i]-w[0][v[2][i]]>w[0][n-m+1]-v[0][n-m1+1])p+=v[0][i]-w[0][v[2][i]]+w[0][n-m+1],v[2][i]=w[2][v[1][i]]=x[2][v[1][i]]=2,m+=1,w[2][m]=v[2][w[1][m]]=x[2][w[1][m]]=1;
				else m1++;
				m=min(n,m);
				break;
			}
			p+=v[0][i];
			v[2][i]=w[2][v[1][i]]=x[2][v[1][i]]=2;
		}
		m1=min(n,m);
		for(int i=n;i>m2;i++){
			if(x[2][i]==1){
				if(x[0][i]-w[0][x[2][i]]>w[0][n-m+1]-x[0][n-m1+1])p+=x[0][i]-w[0][x[2][i]]+w[0][n-m+1],x[2][i]=w[2][x[1][i]]=v[2][x[1][i]]=2,m+=1,w[2][m]=x[2][w[1][m]]=v[2][w[1][m]]=1;
				else m2++;
				m=min(n,m);
				break;
			}
			else if(x[2][i]==2){
				if(x[0][i]-v[0][x[2][i]]>v[0][n-m1+1]-x[0][n-m2+1])p+=x[0][i]-v[0][x[2][i]]+v[0][n-m1+1],x[2][i]=w[2][x[1][i]]=v[2][x[1][i]]=2,m+=1,v[2][m1]=x[2][v[1][m1]]=w[2][v[1][m1]]=1;
				else m2++;
				m1=min(n,m1);
				break;
			}
			p+=x[0][i];
			x[2][i]=w[2][x[1][i]]=v[2][x[1][i]]=3;
		}
	}
	cout<<p<<'\n';
    return 0;
}

