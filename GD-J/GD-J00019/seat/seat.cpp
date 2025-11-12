#include<bits/stdc++.h>
using namespace std;
int zw[11][11],l[101];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,pm;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>l[i];
	}
	sort(l+1,l+n*m,cmp);
	for(int i=1;i<n*m;i++){
		if(l[0]>l[i]){
			pm=i;
			break;
		}
	}
	if(((pm-1)/n)%2==0){
		cout<<(pm-1)/n+1<<" "<<(pm-1)%n+1;
	}
	else{
		cout<<(pm-1)/n+1<<" "<<n-((pm-1)%n);
	}
	return 0;
}


