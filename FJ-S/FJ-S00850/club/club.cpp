#include<bits/stdc++.h>
using namespace std;
int t,n,a[100001][4],b[4],maxx=-1,s=0;
void dfs(int k){
	if(k>n){
	maxx=max(s,maxx);
	return;
	} 
	
	for(int i=1;i<=3;i++){
		if(b[i]>=n/2) continue;
		else{
		int l=a[k][i];
		s+=a[k][i];
		b[i]++;
		dfs(k+1);
		s-=l;
		b[i]--;
		}
	}
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
cin>>t;
while(t--){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	s=0,maxx=-1;
	memset(b,0,sizeof(b));
	dfs(1);
	cout<<maxx<<endl;
} 
return 0;
}
