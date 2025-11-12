#include<bits/stdc++.h>
using namespace std;
int n,a[10000001];
bool vis[10000001];
bool l[5001][5001][50];
long long ans=0;
void asd(int x,int y,int cnt,bool vi[10000001]){
	if(cnt>n){
		return;
	}
	if(l[x][y][cnt]==0){
		if(cnt>=3&&x>2*y){
			ans+=1;
			//cout<<x<<endl;
			ans%=998244353;
		}
		l[x][y][cnt]=1;
	}
	for(int i=1;i<=n;i++){
		if(vi[i]==0){
			vi[i]=1;
			asd(x+a[i],max(y,a[i]),cnt+1,vi);
			asd(x,y,cnt,vi);
			vi[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				l[i][j][k]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			vis[j]=0;
		}
		vis[i]=1;
		asd(a[i],a[i],1,vis);
	} 
	cout<<ans;
	return 0;
}//1 2 3 4 5
/*
<<' '<<y<<' '<<cnt
*/
