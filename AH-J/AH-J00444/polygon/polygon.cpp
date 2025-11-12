#include<bits/stdc++.h>
using namespace std;
int a[5005];
int c[5005];
int q[5005][5];
long long cnt;
void dfs(int n,int s,int m,int d,int o){
	if(m > n){
		return;
	}
	for(int i = m; i <= n; i++){
		if(c[i] == 0){
			continue;
		}
		for(int j = 1; j <= c[i]; j++){
			q[o][0] = i;
			q[o][1] = j;
			//cout<<i<<' '<<j<<endl;
			if(s + j * i > i * 2 && d + j >= 3){
				long long tj = 1;
				for(int k = 1; k <= o; k++){
					//cout<<q[k][0]<<' '<<q[k][1]<<endl;
				    for(int l = c[q[k][0]]; l >= q[k][1]; l--){
						tj *= c[q[k][0]] - l + 1;
						tj %= 998244353;
						//cout<<tj<<endl;
					}
				}
				cnt += tj;
				cnt %= 998244353;
				//cout<<cnt<<endl<<endl;
			}
			dfs(n,s + j * i,i + 1,d + j,o + 1);
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,max1 = 0;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
		c[a[i]]++;
		max1 = max(a[i],max1);
	}
	dfs(max1,0,1,0,1);
	cout<<cnt<<endl;
	return 0;
}
