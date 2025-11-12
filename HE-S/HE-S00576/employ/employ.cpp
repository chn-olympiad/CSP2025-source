#include <bits/stdc++.h>
using namespace std;
int main(){
int n,m; 
char s[n];
int c[505];
	freopen ("employ.in","r",stdin);
	freopen ("employ.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++){
    	cin >> s[i];
	}
	for (int i=1;i<=n;i++){
		cin >> c[i];
	}
	int a=0,b=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
		    if (s[i]==0){
			    a=0;
		    }	
		    if (s[i]==1 && c[i]>i){
		    	a++;
			}
		}
		if (a==m){
			b++;
		}
	}
	cout << b;
	return 0;
	//±£´æÊ± ½â×¢ÊÍ 
}
