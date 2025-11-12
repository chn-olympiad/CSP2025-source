#include<bits/stdc++.h>
using namespace std;
long long a,b,c[4],d[10001][4],e=0,f[4],ff[10001][4],g,aa[10001],bb[10001],cc[10001];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin>>a;
	for(long long i=0;i<a;i++){
		long long b=0,c[4]={0},d[10001][4]={0},e=0,f[4]={0};
		long long ff[10001][4]={0},g=0,aa[10001]={0},bb[10001]={0};
		cin>>b;
		for(long long j=0;j<b;j++){
			cin>>c[0]>>c[1]>>c[2];
			d[j][0]=c[0];d[j][1]=c[1];d[j][2]=c[2];
			ff[j][0]=0;ff[j][1]=1;ff[j][2]=2;
			sort(c,c+2);
			aa[j]=c[2]-c[1];
			bb[j]=j;
		}
		for(long long j=0;j<b;j++){
			e=j;
			for(long long z=j;z<b;z++){
				if(aa[z]<aa[e]){
					e=z;
				}
			}
			swap(aa[j],aa[e]);
			swap(bb[j],bb[e]);
		}
		for(long long j=0;j<b;j++){
			for(long long z=0;z<2;z++){
				if(d[bb[j]][z]<d[bb[j]][z+1]){
					swap(d[bb[j]][z],d[bb[j]][z+1]);
					swap(ff[bb[j]][z],ff[bb[j]][z+1]);
				}
			}
			if(d[bb[j]][0]<d[bb[j]][1]){
				swap(d[bb[j]][0],d[bb[j]][1]);
				swap(ff[bb[j]][0],ff[bb[j]][1]);
			}
			if(f[ff[bb[j]][0]]<b/2){
				f[ff[bb[j]][0]]++;
				g+=d[bb[j]][0];
			}
			else{
				f[ff[bb[j]][1]]++;
				g+=d[bb[j]][1];
			}
		}
		cc[i+1]=g;
	}
	for(long long i=0;i<a;i++){
		cout<<cc[i+1]<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
