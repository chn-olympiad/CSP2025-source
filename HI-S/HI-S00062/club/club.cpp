#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=0,a[1010]; 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&m);
		for(int j=1;j<=m;j++){
			for(int k=1;k<=3;k++){
				scanf("%d",&a[i]);
			}
			cnt+=max(max(a[1],a[2]),a[3]);
		}
	}
	return 0;
} 
