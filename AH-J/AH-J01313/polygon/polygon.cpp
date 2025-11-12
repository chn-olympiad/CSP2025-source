#include <bits/stdc++.h>
using namespace std;
int n;
long long ans = 0;
int a[5005],ls[5005],f[5005],ff[5005],xb[5005];
void dfs(int len,int step){
	if(step==len){
		long long sum = 0,flag = 1;
		int vmax = INT_MIN;
		for(int i = 1;i<=len;i++){
			if(i>1&&(ls[i]<ls[i-1]||xb[i]<xb[i-1])){
				flag = 0;
				break;
			}
			sum+=ls[i];
			vmax = max(vmax,ls[i]);
			//cout << ls[i]<<" ";
		}
		//cout << endl;
		//cout << sum<<" "<<vmax<<endl;
		if(sum>vmax*2&&flag){
			//for(int i = 1;i<=len;i++){
			//	cout << ls[i]<<" ";
			//}
			//cout << endl;
			ans++;
		}
		//step = 0;
		return ;
	}
	for(int i = 1;i<=n;i++){
		if(!f[i]){
			f[i]=1;
			step++;
			ls[step] = a[i];
			xb[step]  = i;
			dfs(len,step);
			step--;
			f[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		ff[a[i]]++;
	}
	if(n<=2){
		cout << 0;
	}
	else if(n==3){
		if((a[1]+a[2]+a[3])>max(max(a[1],a[2]),a[3])){
			cout << 1;
		}
		else{
			cout << 0;
		}
	}
	else{
		for(int i = 3;i<=n;i++){
			memset(f,0,sizeof f);
			memset(ls,0,sizeof ls);
			dfs(i,0);
		}
		cout << ans;
	}
	return 0;
}
