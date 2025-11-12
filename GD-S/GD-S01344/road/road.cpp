#include<bits/stdc++.h>
using namespace std;

int n,m,k;
struct r{
	int m,s,e;
	int f=0;
};
struct c{
	int m,d,a[10000]={0};
	int f=0;
};
r ro[10001]={0};
c co[10001]={0};
int dr(int a){
	int q=0;
	for(int i=1;i<=m;i++){
		if(ro[i].e==a&&ro[i].f!=1){
			ro[i].f=1;
			q+=ro[i].m;
			q+=dr(ro[i].s);
			ro[i].f=0;
			q-=ro[i].m;
		}
	}
	int sf=0;
	for(int i=1;i<=m;i++){
		if(ro[i].f==0){
			for(int j=1;j<=k;j++){
				if(co[j].f==0){
					q+=co[j].m;
					co[j].f=1;
					
				}
				q+=co[j].a[i];
				ro[i].f=1;
			}
			
		}
	}
	return q;

}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;

	for(int i=1;i<=m;i++){
		cin>>ro[i].m>>ro[i].s>>ro[i].e;	
	}
	for(int i=1;i<=k;i++){
		cin>>co[i].m;
		for(int j=1;j<=n;j++){
			cin>>co[i].a[j];
		}
		co[i].d=i;
	}
	cout<<dr(1);
	
	fclose(stdin);
	fclose(stdout); 
	
}
