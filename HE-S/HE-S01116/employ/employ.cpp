#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ".in,"r",stdin);
	freopen("employ".out,"w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++) {
			if(i=1&&j+1+m)
			{
				cout << n;
			}else{
				cout << m;
			}
		} 
		                                                                                                                
	}
	
	return 0;
}
