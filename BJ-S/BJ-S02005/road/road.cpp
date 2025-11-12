#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

int n,m,k,a,v,e,cnt=0;
cin>>n>>m>>k;
for(int i;i<n;i++){
cin>>a>>v>>e;
cnt+=e;

}
cout<<cnt;
fclose(stdin);
fclose(stdout);
return 0;
}
