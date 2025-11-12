#include <bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
string a[N][2],b[N][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++){
		scanf("%s %s",&a[i][0],&a[i][1]);
	}
	for(int i=0;i<q;i++){
		scanf("%s %s",&b[i][0],&b[i][1]);
	}
	return 0;
}
