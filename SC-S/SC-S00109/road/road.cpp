#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
string str[N][2];
int eng[N],maxn;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>str[i][1]>>str[i][2];
		leng[i]=str[i][1].length() ;
		maxn=max(maxn,leng[i]);
	}
	return 0;
}
