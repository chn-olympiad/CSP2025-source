#include<bits/stdc++.h>
using namespace std;
int n,k;
long long m;
long long s[100001][1000001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n;
    cin>>m;
    cin>>k;
    int u;
    int v;
    int w;
    int max1=0;
    int num=0;
    for(long long i=1;i<=m;i++){
	    cin>>u;
	    cin>>v;
	    cin>>w;
	    if(w>max1)
	       max1=w;
	    s[u][v]=w;
	    num+=w;
	}
    cout<<num-max1;
   return 0;
}