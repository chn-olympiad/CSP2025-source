#include<bits/stdc++.h>
using namespace std;
long long t,n,sum=0;
struct club{
	long long a,b,c;
}m[100005];

int cmp(club x,club y){
	return x.a>y.a;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
		cin>>n;
		sum=0;
		for(int i=1;i<=n;i++){
			cin>>m[i].a>>m[i].b>>m[i].c;
			
		}
		sort(1+m,1+m+n,cmp);
		for(int i=1;i<=n/2;i++){
			sum+=m[i].a;
		}
		cout<<sum<<endl;
	}
	
	return 0;
}
