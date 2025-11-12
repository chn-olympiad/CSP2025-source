#include <bits/stdc++.h>
using namespace std;

int t,n,a[100005][100005],sum=0,s[3],wlh=0;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int b,c,z[100005],y[100005];
	cin >> t >> n;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=3;j++){
			cin >> a[i][j];
			s[j]=0;
		}
	}
	if(n==2){
		for (int i=1;i<=n;i++){
			int maxx=0;
			bool flag=true;
			if (flag){
				for (int j=1;j<=3;j++){
					if (a[i][j]>maxx){
						maxx=a[i][j];
					}
				}
				sum+=maxx;
				flag=false;
			}
			else{
				for (int j=1;j<=3;j++){
					if (a[i][1]>a[i][2]){
						b=a[i][2];
						a[i][2]=a[i][1];
						a[i][1]=b;
					}
					if (a[i][2]>a[i][3]){
						c=a[i][3];
						a[i][3]=a[i][2];
						a[i][2]=c;
					}
					if (a[i][1]>c){
						a[i][2]=a[i][1];
						a[i][1]=c;
					}
				}
				sum+=a[i][2];
			}
		}
		cout << sum << endl;
	}
	
	else{
		if (n==4){
			for (int i=1;i<=n;i++){
				int maxx=0,num;
				for (int j=1;j<=3;j++){
					if (a[i][j]>maxx){
						maxx=a[i][j];
						num=j;
					}
				}
				y[i]=maxx;
				z[i]=num;
			}
			for (int i=1;i<=n;i++){
				if (z[1]==z[2] || z[1]==z[3] || z[1]==z[4] || z[2]==z[3] || z[2]==z[4] || z[3]==z[4]){
					wlh++;
					if (wlh>=4){
						wlh==4;
					}
				}
			}
			if (wlh==2){
				for (int i=1;i<=n;i++){
					sum+=y[i];
				}
			}
			if (wlh==3){
				int maxx=0,w=0,nn=0;
				for (int i=1;i<=n;i++){
					if (maxx<y[i]){
						maxx=y[i];
						w=i;
						nn=z[i];
					}
				}
				sum+=maxx;
				maxx=0;
				int wl=0,nnn=0;
				for (int i=1;i<=n;i++){
					if (i!=w){
						if (maxx<y[i]){
						    maxx=y[i];
						    wl=i;
						    nnn=z[i];
					    }
					}
				}
				sum+=maxx;
				maxx=0;
				int wh=0,nnnn=0;
				for (int i=1;i<=n;i++){
					if (i!=w||i!=wl){
						if (maxx<y[i]){
						    maxx=y[i];
						    wh=i;
						    nnnn=z[i];
					    }
					}
				}
				if (nn!=nnn||nn!=nnnn||nnn!=nnnn){
					sum+=maxx;
					int maxn=0;
					for (int i=1;i<=n;i++){
						if (i!=w||i!=wl||i!=wh){
							for (int j=1;j<=3;i++){
						        if (a[i][j]>maxn){
							        maxn=a[i][j];
						        }
					        }
						}
					}
					sum+=maxn;
				}
				else{
					int maxn=0,wh=0;
					for (int i=1;i<=n;i++){
						if (i!=w||i!=wl){
							for (int j=1;j<=3;j++){
								if (a[i][j]>maxn){
									maxn=a[i][j];
									wh=i;
								}
							}
						}
					}
					sum+=maxn;
					maxn=0;
					for (int i=1;i<=n;i++){
						if (i!=w||i!=wh||i!=wl){
							for (int j=1;j<=3;j++){
								if (a[i][j]>maxn){
									maxn=a[i][j];
								}
							}
						}
					}
					sum+=maxn;
				}
			} 
			cout << sum << endl;
		}
	}
	return 0;
}
