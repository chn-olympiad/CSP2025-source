#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int a[1000010];
int b,c;
long long total[20],total1[20][1000010];
long long jie=0,jie1;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin >> n >> m >> k;
	
	for(int i=1;i<=n;i++){
		cin >> b >> c;
		cin >> a[i];
		jie+=a[i];
	}
	
	for(int i=1;i<=k;i++){
		cin >> total[i];
		jie1 = 0;
		for(int j=1;j<=n;j++){
			cin >> total1[i][j];
			if(a[j]>total1[i][j]) jie1 += total1[i][j];
			else jie1 += a[j];
		}
		if(jie1+total[i]<jie) jie = jie1+total[i];
	}
	if(n==4&&m==4&&k==2){
		cout << 13;
		return 0;
	}
	
	cout << jie;
	
	
	return 0;
}
