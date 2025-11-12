#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],dp[N],d[N][3],s,y=1,l,r;
bool bj(int ai,int aj,int bi,int bj){
	if ((bi>=ai && bi<=aj) || (bj>=ai && bj<=aj)) return true;
	return false;
}int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (i!=1){
			dp[i]=a[i]^dp[i-1];
		}else dp[i]=a[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			int z=dp[j]^(dp[i-1]);
			if (z==k){
				d[y][1]=i;
				d[y][2]=j;
				y++;
			}
		}
	}y--;
	for (int i=1;i<=y;i++){
		for (int j=1;j<=y-i;j++){
			if (d[j][2]>d[j+1][2]){
				swap(d[j][1],d[j+1][1]);
				swap(d[j][2],d[j+1][2]);
			}
		}
	}for (int i=1;i<=y;i++){
		if (i==1){
			l=d[i][1];
			r=d[i][2];
			s++;
		}else{
			if (d[i][1]>r){
				s++;
				l=d[i][1];
				r=d[i][2];
			}
		}
	}cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
