#include<bits/stdc++.h>

using namespace std;

int n,m,p;
int f[5010];
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);

cin>>n;
for(int i=1;i<=n;i++){
	cin>>f[i];
}
m=f[1];
p=1;
for(int i=2;i<=n;i++){
	m=max(m,f[i]);
}



return 0;

}
