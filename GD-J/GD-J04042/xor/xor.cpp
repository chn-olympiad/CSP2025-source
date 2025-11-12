#include<bits/stdc++.h>
using namespace std;
int n ,m,s,b;
int a[100001];
int main () {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int g=0;
			for(int k=i;k<=j;k++){
				g^=a[k];
			}
			if(g==m){
			    s++;
			    i=max(i,j);
			    break;
			}
		}
	}
	cout << s;
	return 0;
}
