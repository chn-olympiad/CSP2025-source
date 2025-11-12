#include<bits/stdc++.h>
using namespace std;
#define N 100005
int T,n,k,f[5][N],d[5],x[5],l[5],p;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		k=d[1]=d[2]=d[3]=l[1]=l[2]=l[3]=0;
		for(int i=0;i<n;i++){
			scanf("%d %d %d",&x[1],&x[2],&x[3]);
			if(x[1]>x[2]&&x[1]>x[3]){
				d[1]++;
				k+=x[1];
				f[1][l[1]++]=x[1]-max(x[2],x[3]);
			}
			else if(x[2]>x[3]){
				d[2]++;
				k+=x[2];
				f[2][l[2]++]=x[2]-max(x[1],x[3]);
			}
			else{
				d[3]++;
				k+=x[3];
				f[3][l[3]++]=x[3]-max(x[1],x[2]);
			}
		}
		sort(f[1],f[1]+l[1]);
		sort(f[2],f[2]+l[2]);
		sort(f[3],f[3]+l[3]);
		if(d[1]>d[2]&&d[1]>d[3])
			p=1;
		else if(d[2]>d[3])
			p=2;
		else p=3;
		for(int i=0;i<d[p]-n/2;i++)
			k-=f[p][i];
		cout<<k<<endl;
	}
	return 0;
}
