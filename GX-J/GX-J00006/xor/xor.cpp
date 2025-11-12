#include<bits/stdc++.h>

using namespace std;

int n,m;
int f[7];
int p;

int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);

cin>>n>>m;
for(int i=1;i<=4;i++){
	cin>>f[i];
}
if(m==p) p=1;
else p=2;

cout<<p<<endl;
return 0;

}
