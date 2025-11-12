#include<bits/stdc++.h>
using namespace std;
int main()
{
	/*freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);*/
	int ii[1][2];
	string jf[6][2];
	for(int i = 0;i <= 2;i++){
		cin>>ii[1][2];
	}
	for(int j = 0;j <= 5;j++){
		cin>>jf[6][2];
	}
	for(i = 0;i <= n;i++){
		for(int j = 0;j <= n;j++){
			cin >> a[n];
			if(jf[j][j - 1] < jf[j + 1][j - 1])
				sum = jf[j + 1][j - 1] - jf[j][j - 1];
			else
				sum = jf[j][j - 1] - jf[j + 1][j - 1];
		}
	cout<<sum<<endl;
	}
	/*fclose(stdin);
	fclose(stdout);*/
	return 0;
}
