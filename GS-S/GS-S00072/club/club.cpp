#include<bits/stdc++.h>
using namespace std;
int main(){
	/*freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);*/
	int t,n,sum = 0,i = 0;
	cin >> t;
	cin >> n;
	int a[n];
	while(i <= t){
		for(i = 0;i <= n;i++){
			for(int j = 0;j <= n;j++){
				cin >> a[n];
				if(a[j]<a[j + 1])
					sum = sum + a[j + 1];
				else
					sum = sum + a[j];
			}
		cout<<sum<<endl;
		}
	}
	/*fclose(stdin);
	fclose(stdout);*/
	return 0;
}
