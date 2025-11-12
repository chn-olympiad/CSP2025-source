#include<bits/stdc++.h>

const int N=1e5+7;

using namespace std;

int n, d[6][N], h1[N];

int main(){
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin>>t;
	while(t--){
		memset(d, 0, sizeof(d));
		memset(h1, 0, sizeof(h1));
		int c1=0, c2=0, c3=0, maxx=0;
		cin>>n;
		for(int i=1; i<=n; i++){
			cin>>d[1][i]>>d[2][i]>>d[3][i];
			maxx+=max(d[1][i], max(d[2][i], d[3][i]));
			if(d[1][i]==max(d[1][i], max(d[2][i], d[3][i]))){
				c1++;
			}
			else if(d[2][i]==max(d[1][i], max(d[2][i], d[3][i]))){
				c2++;
			}
			else if(d[3][i]==max(d[1][i], max(d[2][i], d[3][i]))){
				c3++;
			}
		}
		if(c1<=n/2 && c2<=n/2 && c3<=n/2){
			cout<<maxx<<"\n";
		}
		else {
			int y, yy;
			if(c1==max(c1, max(c2, c3)))y=1, yy=c1;
			else if(c2==max(c1, max(c2, c3)))y=2, yy=c2;
			else if(c3==max(c1, max(c2, c3)))y=3, yy=c3;
			for(int i=1; i<=n; i++){
				h1[i]=INT_MAX;
				if(d[y][i]!=max(d[1][i], max(d[2][i], d[3][i])))continue;
				int max1=0;
				h1[i]=d[y][i];
				for(int j=1; j<=3; j++){
					if(j!=y) max1=max(max1, d[j][i]);
				}
				h1[i]-=max1;
			}
			sort(h1+1, h1+n+1);
			for(int i=1; i<=yy-n/2; i++)	{
				maxx-=h1[i];
			}
			cout<<maxx<<"\n";
		}
	}
	return 0;
}

