#include<bits/stdc++.h>
using namespace std;
long long int t,n;
const int N=1e4+15;
int a,b,c,d,e;
int x[N],y[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(x,N,sizeof(x));
	memset(y,N,sizeof(y));
	int n,m,num;
    cin>>n>>m>>num;
    int l=4;
    for(int i=1;i<=l;i++){
        cin>>a>>b>>c;
    	x[a]=min(x[a],b);
    	x[b]=min(x[b],c);
	}
	for(int i=1;i<=n;i++){
		if(x[i]<N){
			y[num]=x[i];
			num++;
		}
	}
	int lk;
	for(int i=1;i<=lk;i++){
		if(y[i]!=y[i-1]){
			num+=y[i];
		}
	}
	cout<<num<<endl;
	return 0;
}

