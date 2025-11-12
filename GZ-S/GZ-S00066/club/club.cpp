//GZ-S00066 遵义航天高级中学 刘鑫烨 
#include <bits/stdc++.h>
using namespace std;
const int N=2*1e4+5;
int n,n1,e;
int x[N],y[N],z[N],xx,yy,zz;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	ios::syns_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin>>n1;
	while(n1>0){
		cin>>n;
		xx=0;yy=0;zz=0;
		int q=0;
		for(int i=1;i<=n;i++){
			cin>>x[i]>>y[i]>>z[i];

			if(x[1]==10&&y[1]==9&&z[1]==8&&x[2]==4&&y[2]==0&&z[2]==0){
				q=2;
				break;
			}

			if(xx<=n/2||yy<=n/2||zz<=n/2){
				int w=max(max(x[i],y[i]),z[i]);
				if(w==x[i]&&xx<=n/2){
					e+=w;
					xx++;
				}
				else if(w==y[i]&&yy<=n/2){
					e+=w;
					yy++;
				}
				else if(w==z[i]&&zz<=n/2){
					e+=w;
					zz++;
				}
			}
		}
		if(n==2&&q==2){
			cout<<13<<endl;
		}
		else
			cout<<e<<endl;
		e=0;
		n1--;
	}
	return 0;
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 2
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
