#include<bits/stdc++.h>
using namespace std;
const int mo = 998244353;
long long ans,a[5010],n,cnt;
struct v{
	long long d;
	long long ma=-1;
}v[5010][5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n);
	for(int i=1;i<=n;i++){
		v[i][i].d = a[i];
		v[i][i].ma = a[i];
	}	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			v[i][j].d = max(v[i][j].d,v[i][j-1].d+a[j]);
			v[i][j].ma = max(v[i][j].ma,a[j]);
			for(int h=i+1;h<=j;h++){
				for(int l=h;l<j;l++){
					if(v[i][j].d>v[i][j].ma*2||v[i][j].d-v[h][l].d>2*max(v[i][j].ma,v[h][l].ma))cnt++;
				}
			}
		}
	}
	printf("%d",cnt%mo);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
