#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdin);
	int m,n[7],a[7][10005][7];
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>n[i];
		for(int k=1;k<=m;k++){
				for(int j=1;j<=n[i];j++){
					cin>>a[j][k][i];
			}
		}
	}
	for(int k=1;k<=m;k++){
		int s=0;
		for(int i=1;i<=m;i++){
			int p=0;
			for(int j=1;j<=n[k];j++){
				p=max(a[k][j][i],p);
			}
			s+=p;
		}
		cout<<s<<" ";
	}
}
