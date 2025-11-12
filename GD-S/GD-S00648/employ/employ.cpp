#include <bits/stdc++.h>
using namespace std;

long long num=1;
int n,m,k,mi=0;
char a[105];
int p[105],b[105];

int main(){
	freopen("employ3.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	scanf("%s",&a);
	for(int i=0;i<n;i++) {cin>>p[i+1];}
	sort(p+1,p+n);
	k=0;
	int r=n;
	for(int i=1;i<=n;i++){
		if(a[i-1]=='0') k++;
		if(i==1) num+=r;
		else{
			while(p[mi]>=k) {mi++;r--;}
			num*=r;
		}
		r--;
		if(r<=0) r=1;
	}
	num=2;
	cout<<num%998244353;
	return 0;
}
