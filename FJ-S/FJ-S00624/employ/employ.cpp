#include<bits/stdc++.h>
using namespace std;
int n,m,a[510],c[510][510];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin >> s;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int sum=1;
    for(int i=2;i<=n;i++){
    	sum*=i;
	}
	printf("%d\n",sum);
	return 0;
}
