#include <iostream>
using namespace std;
int t,n,sum=0,a[995][995],b[10],c[10],pos;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i = 1;i <= t;i++){
		cin >> n;
		for(int j = 1;j <= n;j++){
			for(int k = 1;k <= 3;k++){
				cin >> a[j][k];
			}
		}
		sum=0;
		int flag[5]={};
		for(int j = 1;j <= n;j++){
			int maxn=0;
			for(int k = 1;k <= 3;k++){
				int al=max(a[j+1][k+2],max(a[j+1][k],a[j+1][k+1]));
				if(flag[k]>=n/2){
					maxn=max(a[j][k+1]+al,a[j][k+2]+al);
					pos=k+1;
				}
				else if(maxn <=  a[j][k] && flag[k] < n/2){
					maxn=a[j][k];
					pos=k;
				}
			}
			sum+=maxn;
			flag[pos]++;
		}
		cout << sum << '\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

