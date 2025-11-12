#include <bits/stdc++.h>
using namespace std;
int main(){
int n,q;
char s[n][n];
char t[q][q];
	freopen ("replace.in","r",stdin);
	freopen ("replace.out","w",stdout);
    cin >> n >> q;
    for (int i=1;i<=n;i++){
    	for (int j=1;j<=i+1;j++){
    		cin >> s[i][j];
		}
	}
	for (int i=1;i<=q;i++){
		for (int j=1;j<=i+n+1;j++){
			cin >> t[i][j];
		}
	}
	int x,z;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=q;j++){
			if (s[i][j]==t[i][j]){
				t[i][j]==s[i][j+1];
			}
			if (s[i][j]==x+t[i][j]+z){
				s[i][j+1]==x+t[i][j+1]+z;
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=q;j++){
			
		}
	}
	return 0;
	//±£´æÊ± ½â×¢ÊÍ 
}
