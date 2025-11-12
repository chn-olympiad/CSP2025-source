#include<iostream>
#include<fstream>
using namespace std;
int n,a[5001],I,J;
long long allsum,sumn,maxn,max_;
void dfs(int N,int idx){
	if(N==I){
		//cout<<"sumn="<<sumn<<" maxn="<<maxn<<"  "<<(sumn>maxn*2?"YES\n":"NO\n");
		if(sumn>maxn*2) allsum++;
		return ;
	}for(int i=idx;i<n;i++){
		sumn+=a[i];
		max_=maxn;
		maxn=(maxn<a[i]?a[i]:maxn);
		//cout<<a[i]<<' ';
		dfs(N+1,i+1);
		sumn-=a[i];
		maxn=max_;
	}
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	for(I=0;I<n;I++)cin>>a[I];
	for(I=3;I<=n;I++){
		sumn=0;
		maxn=0;
		dfs(0,0);
		//cout<<"\n\n";
	}
	cout<<allsum;
	

    return 0;
}

