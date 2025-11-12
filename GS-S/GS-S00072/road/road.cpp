#include<bits/stdc++.h>
using namespace std;
int main()
{
	/*freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);*/
	int n,m,k,sum;
	int a[3][m];
	int b[n][n + 1];
	for(int i = 0;i <= m;i++){
		cin>>a[3][m];
	}
	for(int i = 0;i <= (n + 1);i++){
		cin>>b[n][n + 1];
	}
	for(i = 0;i <= n;i++){
		for(int j = 0;j <= n;j++){
			if(a[j]>a[j + 1]){
				sum = sum + a[j + 1];
			}
			else{
				sum = sum + a[j];
			}
		}
		cout<<sum<<endl;
	}
	/*fclose(stdin);
	fclose(stdout);*/
	return 0;
}
