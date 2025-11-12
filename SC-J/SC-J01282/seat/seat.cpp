#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105][105],b[20005],rr;
void dfs(long long x,long long y,long long cnt){
	if(cnt==n*m){
		return ;
	}
	cnt++;
	if(a[x][y+1]==0 && y+1<=n){
		a[x][y+1]=b[cnt];
		dfs(x,y+1,cnt);
	}else if(a[x][y-1]==0 && y-1>=1){
		a[x][y-1]=b[cnt];
		dfs(x,y-1,cnt);
	}else{
		a[x+1][y]=b[cnt];
		dfs(x+1,y,cnt);
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	rr=b[1];
	sort(b+1,b+n*m+1);
	for(int i=1;i<=n*m/2;i++){
		long long o=b[i];
		b[i]=b[n*m-i+1];
		b[n*m-i+1]=o;
	}
//	for(int i=1;i<=n*m;i++){
//		cout<<b[i]<<" ";	
//	}
//	cout<<a[1][1];
	a[1][1]=b[1];
	dfs(1,1,1);
	bool kk=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==rr){
				cout<<i<<" "<<j;
				kk=1;
				break;
			}
		}
		if(kk==1){
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;

}
