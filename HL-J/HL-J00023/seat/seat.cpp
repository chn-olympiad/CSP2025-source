#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000],t,ansn,ansm,l;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<m*n;i++){
		cin>>a[i];
	}t=a[0];
	sort(a,a+m*n,cmp);
	for(int i=0;i<m*n;i++){
		if(a[i]==t){
			l=i+1;
			break;
		}
	}
	if(l%n==0){
		ansm=l/n;
	}else{
		ansm=l/n+1;
	}
	if(ansm%2==0){
		ansn=n-(l-(ansm-1)*n)+1;
	}else{
		ansn=l-(ansm-1)*n;
	}cout<<ansm<<" "<<ansn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}