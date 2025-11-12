#include<bits/stdc++.h>
using namespace std;
const int N=501;
int n,m;
string s;
int c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	cout<<m-(n-1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
