#include<bits/stdc++.h>
using namespace std;
int a[105],pm,r;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)r=a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			pm=i;
			break;
		}
	}
	for(int i=1;;){
		for(int j=1;;){
			if((i==n&&j%2==1)||(i==1&&j%2==0)){
				j++;
			}else if(j%2==1){
				i++;
			}else if(j%2==0){
				i--;
			}
			pm--;
			if(pm==1){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
