#include<bits/stdc++.h>
using namespace std;
int n,m;
int c[510];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m;
	cin >> s;
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	cout << m;
	fclose(stdin);
	fclose(stdout);
    return 0;
}

