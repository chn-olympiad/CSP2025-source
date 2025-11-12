#include <bits/stdc++.h>
using namespace std;
int n,m,a[10010],score,pi=0,pj=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>score; a[1]=score;
	for(int i=2;i<=n*m;i++)
		cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	bool f=1;
	for(int i=1;i<=n*m;i++){
		if(f){
			pi++;
			if(pi>n){pj++; f=0; pi--;}
		}
		else{
			pi--;
			if(pi==0){pj++; f=1; pi++;}
		}
		if(a[i]==score){
			cout<<pj<<" "<<pi;
			return 0;
		}
	}
	return 0;
}
