#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,m;
int a[N][N],b[N],cnt=0,r;
bool cmp(int o,int p){
	if(o>p)return true;
	return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>b[i];
		if(i==0)r=b[i];
	}
	sort(b,b+n*m,cmp);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(b[cnt++]==r)cout<<i+1<<" "<<j+1;
		}
		if(i==m)continue;
		i++;
		for(int j=m-1;j>=0;j--){
			if(b[cnt++]==r)cout<<i+1<<" "<<j+1;
		}	
	}
	
	return 0;
}
