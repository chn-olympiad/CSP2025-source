#include<bits/stdc++.h>
using namespace std;
long long n,m;
int k;
long long u[1000010],v[1000010],w[1000010],c[20],a[20][1000010];
int main(){
	freopen("road.in","r",stdin);
	freopen("read.out","w",stdout);
	cin>>n>>m>>k;
	long long sb[m+10];
	for(int i = 1;i <= m;i++){
		cin>>u[i]>>v[i]>>w[i];
		sb[i] = w[i];
	}
	for(int j = 1;j <= k;j++){
		cin>>c[j];
		for(int e = 1;e <= m;e++) cin>>a[j][e];
	}
	sort(sb+1,sb+1+m);
	long long sum = 0;
	for(int i = 1;i <= m;i++){
		int h=0;
		for(int j = 1;j <= m;j++){
			if(j!=i){
				if(w[i]==sb[1] && w[j]==sb[2] || w[i]==sb[2] && w[j]==sb[1]){
			        if(u[i]==u[j] || v[i]==v[j] || u[i]==v[j] || v[i]==u[j]) sum+=sb[1]+sb[2]; h++; break;
		        }    
			}
		}
		if(h) break;
	}
	sort(c+1,c+1+k);
	sum+=c[1];
	int g = c[1];
	for(int j = 1;j <= k;j++){
		if(g==c[j]){
			for(int e = 1;e <= m;e++){
				sb[e] = a[j][e];
			}
		}
	}
	sort(sb+1,sb+1+m);
	sum+=sb[1]+sb[2];
	cout<<sum;
	return 0;
}
/*4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4*/
