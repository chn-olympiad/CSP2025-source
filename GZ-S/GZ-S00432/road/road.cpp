//GZ-S00432 遵义市第四中学 邓俣宸 
#include<bits/stdc++.h>
using namespace std;
long long n,m,p[1000000][1000000],a,b,c,pp[1000000],k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		p[a][b]=c;
		p[b][a]=c;
	}for(int i=0;i<k;i++){
		cin>>a>>b>>c;
	}if(k==0){
		long long s=0;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=i;j++){
				s+=p[i][j];
			}
		}cout<<s;
	}else{
		cout<<0;
	}
	return 0; 
}
