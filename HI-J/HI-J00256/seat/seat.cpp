#include<bits/stdc++.h>
freopen("seat.in","seat.in",stdin);
freopen("out.txt","seat.out",stdout);
using namespace std;
int main(){
	int n,m,Max=-10,next=-1;
	cin>>n>>m;
	int a[n*m+5];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n*m;j++){
		for(int i=1;i<=n*m;i++){
		if(a[i]>=Max){
		Max=a[i];
		}
		}
		if(a[1]==Max){
		cout<<"1 1";
		return 0;
		}
		for(int i=1;i<=n*m;i++){
		if(a[i]==Max){a[i]==-10;}
		}
	    }
		if(Max-a[1]<n){
		cout<<1<<" "<<Max-a[1]+1;return 0;
		}
		else{
			if(Max-a[1]>=2*n){
			cout<<m<<" "<<1;return 0;
			}
			cout<<m<<" "<<n;
		}
	return 0;
}

