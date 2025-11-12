#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("road".in,"r",stdin);
	freopen("road".out,"w",stdout);
	int n,m;
	int k;
	cin >> k;
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=k;j++){
			if(i+1&&j+m+1)
	{
			cout << n; 
		}else{
			cout << m;
		}	
	}
}
return 0;
}
