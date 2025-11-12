#include<bits/stdc++.h>
using namespace std;
const int N=3e6+10;
int n,k,xl[N],qzh[N],qj[N][N],ans;
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>xl[i];
		qzh[i]=xl[i]^xl[i-1];
	}
	int x=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(qzh[j]-qzh[i-1]==k){
				qj[++x][0]=i;
				qj[x][1]=j;
				ans++;
			}
		}
	}
	cout<<ans; 
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
}
