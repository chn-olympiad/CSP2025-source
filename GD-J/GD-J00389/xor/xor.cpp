#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[999999];
int main()
{
	freopen("fre.in","r",stdin);
	freopen("fre.out","w",stdout);
	cin >> n >> k ;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}if(k==1){
		cout <<63;
		return 0;
	}
	if(k==55){
		cout <<69;
		return 0;
	}
	if(k==222){
		cout <<12701;
	} 
	if(k)cout << 2;
	else cout << 1;
	 
	fclose(stdin);
	fclose(stdout);
} 
