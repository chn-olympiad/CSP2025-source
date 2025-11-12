#include <bits/stdc++.h>
using namespace std;
int n,m,x;
string s;
int a[1010];
int A[1010];
const int Mod=998244353;
void Ad(int x){
	A[1]=1;
	for(int i=1;i<=x;i++){
		A[i]=i*A[i-1]%Mod;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	Ad(n);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		if(s[i]=='1')x++;
	}
	if(x<m){
		printf("0\n");
		return 0;
	}
	if(x==n){
		printf("%d\n",A[n]);
		return  0;
	}
	return 0;
}
