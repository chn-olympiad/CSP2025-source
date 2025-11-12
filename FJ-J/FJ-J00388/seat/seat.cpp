#include<bits/stdc++.h>
using namespace std;
int zw[10001][10001];
int n,m;
int a[10001];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int j=0;j<n*m;j++){
		cin>>a[j];
	}
	int y=a[0];
	int q=0;
	sort(a,a+n*m,cmp);
	for(int j=0;j<=n*m;j++){
		if(a[j]==y){
			q=j;
		}
    }
    cout<<q<<endl;
    cout<< q/n+1<<" ";
    if((q%(2*n)<=n-1)&&(q%(2*n)!=0)){
    	cout<<(q+1)/n+1 ;
	}else{
		if(n%2!=0){
			cout<<n-((q-1)%n);
			return 0;
		}
		cout<<n-(q%n);
	}
    
}
