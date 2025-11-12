#include<bits/stdc++.h>
using namespace std;
int n,m;
struct s{
	string a;
	string b;
}c[5000004];
struct t{
	string q;
	string w;
}p[5000004];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>m;
	for(int uy=1;uy<=n;uy++){
		cin>>c[uy].a>>c[uy].b;
	}
	for(int i=1;i<=m;i++){
		cin>>p[i].q>>p[i].w;
	}
	for(int i=1;i<=m;i++){
		int h=0;
		for(int j=1;j<=n;j++){
			if(p[i].q==c[j].a&&p[i].w==c[j].b){
				h++;
				h++;
			}
		}
		string qw,nm;
		int z=1;
		for(int j=1;j<=max(p[i].q.size(),p[i].w.size());j++){
			if(p[i].q[j]!=p[i].w[j]){
				qw[z]=p[i].w[j];
				nm[z]=p[i].q[j];
				z++;
			}
		}
		/*for(int j=1;j<=z;j++){
			cout<<qw[j];
		} 
		for(int j=1;j<=z;j++){
			cout<<nm[j];
		}*/
		for(int j=1;j<=n;j++){
			if(qw==c[j].b&&nm==c[j].a){
				h++;
			}
		}
		cout<<h<<endl;
	}
} 

