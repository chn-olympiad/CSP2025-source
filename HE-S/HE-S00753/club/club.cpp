#include<bits/stdc++.h>
using namespace std;
int a[100010][5];
int c[100010];

int b[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		int m;
		cin>>m;
		for(int j=1;j<=m;++j){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
		}
		if(m==2){
			b[i]=max(max(max(max(max(max(a[1][1]+a[2][2],0),a[1][1]+a[2][3]),a[1][2]+a[1+1][1]),a[1][2]+a[1+1][3]),a[1][3]+a[1+1][1]),a[1][3]+a[1+1][2]);
		}
		bool z=true;
		for(int j=1;j<=m;++j){
			if(a[j][2]!=0||a[j][3]!=0){
				z=false;
			}
		}
		if(z==true){
			int big=0;
			for(int j=1;j<=m;++j){
				c[j]=a[j][1];
			}
			sort(c+1,c+m+1);
			b[i]=c[m]+c[m-1];
		}
	}
	for(int i=1;i<=n;++i){
		cout<<b[i]<<endl;
	};
	return 0;
	/*for(int i=1;i<=n;++i){
		int m;
		cin>>m;
		int q=0,w=0,e=0;
		for(int j=1;j<=m;++j){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			int bi=max(a[j][1],max(a[j][2],a[j][3]));
			if(bi==a[i][1]&&q<=m/2){
				q++;
				b[i]+=a[i][]
			}
			
		}
		
	}
	for(int i=1;i<=n;++i){
		cout<<b[i]<<' ';
	}*/
}
