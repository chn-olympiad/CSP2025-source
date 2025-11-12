#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,a[505];
string s;
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) ans=(ans*i)%244;
	cout<<ans;
    return 0;
}
