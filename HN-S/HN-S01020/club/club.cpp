#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,i[100000][3],sam[100000];
	cin >> t;
	for(int j=1;j<=t;j++){
		cin >> n;
		for(int q=1;q<=n;q++){
			for(int a=1;a<=3;a++){
				cin >> i[q][a];
				if(i[q][a]>=i[q][0]){
					i[q][0]=i[q][a];
				}
				
			}
			sam[j]+=i[q][0];
			
		}
		cout << sam[j] << endl;
	}
	return 0;
}
