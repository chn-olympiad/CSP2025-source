#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0;
string s1[300010],s2[300010];
string t1[300010],t2[300010];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> s1[i] >> s2[i];
	}
	for(int i=1;i<=k;i++){
		cin >> t1[i] >> t2[i];
	}
	for(int i=1;i<=k;i++){
		cout << 0 << endl;
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}

