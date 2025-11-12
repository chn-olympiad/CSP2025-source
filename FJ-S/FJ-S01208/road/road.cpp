#include<bits/stdc++.h>
using namespace std;
long long n,m,k,sum=0,v[1145][1145],v1[1145][1145],ss=0;
struct s{
	int u,v,w;
}s[10005];
struct c{
	int c,a;
}c[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>s[i].u>>s[i].v>>s[i].w;
	}
	for(int i=0;i<k;i++){
		cin>>c[i].c;
		for(int j=0;j<n;j++){
			cin>>c[j].a;
		}
	}
	while(ss<n-1){
		for(int j=0;j<m;j++){
			if(v1[s[j].u][s[j].v]!=1&&c[j].c==s[j].u){
				for(int i=0;i<n;i++){
					if(i==s[j].v&&s[j].w>=c[i].a){
						sum=c[i].a+sum+c[j].c;
						v1[s[j].u][s[j].v]=1;
						ss++;
					}else{
						sum+=s[i].w;
						v1[s[j].u][s[j].v]=1;
						ss++;
					}
				}
			}
			
		}
	}
	cout<<sum;
	return 0;
}
