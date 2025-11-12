#include<iostream>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","r",stdout);
	int d[5],b;
	int a[1000][1000],maxx=0;
	int t;
	cin>>t;
	int n;
	cin>>n;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int u=1;u<=n;u++){
			for(int o=1;o<=3;o++){
				cin>>a[u][o];
			}
			if(a[u][1]>=maxx){
				maxx=a[u][1];
				b=1;
			}
			if(a[u][2]>=maxx){
				maxx=a[u][2];
				b=2;
			}
				
			if(a[u][3]>=maxx){
				maxx=a[u][3];
				b=3;
			}
			d[b]+=maxx;
		}
	}
	cout<<d[1]<<endl<<d[2]<<endl<<d[3];
	return 0;
}
