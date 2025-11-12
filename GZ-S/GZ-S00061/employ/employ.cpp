//GZ-S00061 华东师范大学附属贵阳学校 刘睿羽
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e5+5;
int a[N];
string s;
ll sum1=1,sum2=1;
int n,m;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		sum1*=i;
	}
	for (int i=1;i<=m;i++){
		sum2*=i;
	}
	cout<<(sum1/sum2)%998244353;
	return 0;
}
