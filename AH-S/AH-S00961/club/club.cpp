#include<bits/stdc++.h>
using namespace std;
int x[100005],y[100005],z[100005];
int cmp(int q,int w){
		return q>w;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int maxx=0;
		if(n==2){
			int a,b,c,a1,b1,c1;
			cin>>a>>b>>c;
			cin>>a1>>b1>>c1;
			if(a+b1>maxx)maxx=a+b1;
			if(a+c1>maxx)maxx=a+c1;
			if(b+a1>maxx)maxx=b+a1;
			if(b+c1>maxx)maxx=b+c1;
			if(c+a1>maxx)maxx=c+a1;
			if(c+b1>maxx)maxx=c+b1;
			cout<<maxx<<endl;
		}
		else{
			for(int i=1;i<=n;i++){
				cin>>x[i]>>y[i]>>z[i];
			}
			sort(x+1,x+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				maxx+=x[i];
			}
			cout<<maxx<<endl;
		}
	}
	return 0;
}
