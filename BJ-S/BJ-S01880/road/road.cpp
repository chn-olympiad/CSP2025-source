#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	int n,m,k,a[999999],litter[999999],spend=0;
	cin >> n >> m >> k;
	for (int i = 0;i<m;i++)
	{
		for (int j = 0;j<3;j++){
			if (j==2)
				cin >> a[i];
			else
				cin >> litter[2*i+j];
		}			
	}
	for (int i = 0;i<=m;i++)
	{
		if (a!=0){
			if (a[i]>a[i-1])std::swap(a[i],a[i-1]);
		}
	}
	for (int i = 0;i<=n-1;i++)spend+=a[i];
	cout << spend;
	return 0;
}
