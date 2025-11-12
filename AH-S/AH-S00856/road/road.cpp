#include<bits/stdc++.h>
using namespace std;
long long n,m,k,cnt;
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
cin>>n>>m>>k;
for(int i=0;i<m;i++){
	int a,b,c;
	cin>>a>>b>>c;
	cnt+=c;
}
for(int i=0;i<k;i++){
	for(int j=0;j<=n;j++)cin>>m;
}
cout<<cnt;
return 0;
}
