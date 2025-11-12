#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
int a[N][6],n,t,d[N],e[5],c;
long long res,st;
bool b[N];
void dfs(int l){
	if(b[l]) return;
	if(l>n) return;
	for(int i=1;i<=c;i++){
		if(d[i]>=(n>>1)) continue;
		st=st+a[l][i];
		d[i]+=1;
		b[l]=true;
		dfs(l+1);
		res=max(res,st);
		st-=a[l][i];
		d[i]-=1;
		b[l]=false;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t>0){
		res=0;
		st=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]==0){
					e[j]++;
				}
			}
		}
		c=3;
		if(e[2]==n&&e[3]==n){
			c=1;
		}
		if(e[3]==n) c=2;
		dfs(1);
		cout<<res<<endl;
		t--;
	}
    return 0;
}
