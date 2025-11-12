#include <bits/stdc++.h> 
using namespace std;
	struct f{
		int q;
	};
	bool cmp(f x, f y){
		if(x.q > y.q){
			return 1;
		}
		
			else {
			
			return 0;
		}
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	int n, m;
	int r=a[0];
	int s=0;
	cin>>n>>m;
	long long a[m*n];
	for(int i= 0; i<=m*n; i++){
		cin>>a[i];
	}
	sort(a, a+m*n, cmp);
	for(int i= 0; i<=m*n; i++){
		if(a[i]==r){
			s=i-1;
		}
	}
	if(s=n)
	{
		cout<<1<<m;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
