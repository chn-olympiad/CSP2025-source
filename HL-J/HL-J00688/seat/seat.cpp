#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=110;
int a[N];
void f(int s[],int k){
	for(int i=k-1;i>=1;i--){
		int tmp=s[i];
		int j;
		for(j=i+1;j<=k;j++){
			if(s[j]<tmp) break;
			if(s[j]>tmp) s[j-1]=s[j];
		}
		s[j-1]=tmp;
	}
	return;
}
void dfs(int x,int y,int dep){
	if(dep==1){
		cout << y << " " << x << endl;
		return;
	}
	if(y%2==1 && x<n) dfs(x+1,y,dep-1);
	else if(y%2==1 && x==n) dfs(x,y+1,dep-1);
	else if(y%2==0 && x>1) dfs(x-1,y,dep-1);
	else if(y%2==0 && x==1) dfs(x,y+1,dep-1);
	return;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	int e=a[1],d;
	f(a,n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==e){
			d=i;
			break;
		}
	}
	dfs(1,1,d);
	return 0;
}
