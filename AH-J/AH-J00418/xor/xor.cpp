#include <bits/stdc++.h>
using namespace std;
int x[500005];
struct node{
	int x,y;
}a[500005];
bool cmp(node a,node b){
	if(a.y==b.y){
		return a.x>b.x;
	}
	return a.y<b.y;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		x[i]^=x[i-1];
	}
	for(int i=1;i<=n;i++){
		a[i].x=i;
		a[i].y=1e9;
		for(int j=i;j<=n;j++){
			int m=x[i-1];
			m^=x[j];
			if(m==k){
				a[i].y=j;
				break;
			}
		}
		//cout<<a[i].x<<" "<<a[i].y<<endl;
	}
	sort(a+1,a+1+n,cmp);
	int end=a[1].y,ans=1;
	for(int i=2;i<=n;i++){
		if(a[i].x>end&&a[i].y!=1e9){
			ans++;
			end=a[i].y;
			//cout<<i<<endl;
		}
	}
	cout<<ans;
	return 0;
}/*
4 2
2 1 0 3
4 0
2 1 0 3
4 3
2 1 0 3
70pts
*/
