#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[512],bf[512];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	int z=n,a=0;
	cin >> s;
	for(int i=1;i<=n;i++){
	      	cin >> c[i];
		bf[i]=c[i];
		if(c[i]==0){
			z--;
			a++;
			if(z==0){
				cout << 0;
				break;
			}
		}
	}	
	for(int i=1;i<=n;i++){
		if(a>=c[i]){
			z--;
			a++;
		}
		if(z==0) {
			cout << 0;
			break;
		}
	}
	sort(bf+1,bf+1+n);
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			bf[i]--;
			if(bf[i]==0){
				z--;
				if(z==0 or z>m) break;
			}
		}
		if(z==0 or z==1){
			cout << 0;
			break;
		}
		if(z > m){
			cout << 0 ;
			break;
		}
		z--;
	}
	if(z<=m) cout << 1;
	return 0;
}
