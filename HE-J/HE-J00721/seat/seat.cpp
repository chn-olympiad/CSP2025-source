#include <bits/stdc++.h>
using namespace std;
int a[12][12];
int pe[105];
bool cha(int a,int b) {
	if(a>b) {
		return a,b;
	}
	if(b>a) {
		return b,a;
	}
}


int main() {
	freopen("seat.out","w",stdout);
	int n,m,now=0,di=1;//nli
	freopen("seat.in","r",stdin);//a=97,z=122,0=48,1=49,9=57
	cin>>m>>n;
	for(int i=1; i<=n*m; i++) {
		cin>>pe[i];
	}
	int R=pe[1];
	sort(pe,pe+n*m,cha);


	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {

			now++;
			a[i][j]=pe[now];
			if(a[i][j]==R) {
				cout<<i<<" "<<j;
				return 0;
			}

			//;
		}
		i++;
		for(int j=m+1; j>=1; j--) {

			now++;
			a[i][j]=pe[now];
			if(a[i][j]==R) {
				cout<<i<<" "<<j;
				return 0;
			}

			//;
		}
	}

	return 0;
}
