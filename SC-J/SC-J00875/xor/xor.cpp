#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005][3],ant;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i][1];
	}
	for(int i=1;i<=n;i++){
		int x=-1,y,j=i;
		y=i;
		x=max(a[j][1],a[j+1][1])-min(a[j][1],a[j+1][1]);
		while(x!=k&&j<=n){
			x=max(x,a[j+1][1])-min(x,a[j+1][1]);
			a[j][2]=1;
			j++;
		}
		if(j>n){
			for(int q=y;q<=n;q++){
				a[q][2]=0;
			}
			continue;
		}
		if(j<=n){
			ant++;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i][2]==0&&a[i][1]==k){
			ant++;
		}
	}
	cout<<ant;
	return 0;
}
