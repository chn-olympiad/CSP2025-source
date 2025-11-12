#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("club".in,"r",stdin);
	freopen("club".out,"w",stdout);
	int n;
	int t;
	cin>> t;
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(i>=1&&j<=3)
		{
			cout << "t";
		}else{
			cout << "n";
		}
	}
}
return 0;
}
