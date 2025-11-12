#include<bits/stdc++.h>
using namespace std;
int n,m,a[505];
string s;
void print(int n){
	long long k=1;
	for(int i=2;i<=n;i++){
		k*=i;
		k%=998244353;
	}cout<<k;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	scanf("%s",&s);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}print(n);
	return 0;
}