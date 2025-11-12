#include<bits/stdc++.h>
using namespace std;
int a[105];
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
	}
	int p=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==p){
			p=i;break;
		}
	}
	int lie=(p-1)/n+1;
	int hang=p-(lie-1)*n;
	if(lie%2==1){
		cout<<lie<<' '<<hang;
	}else{
		cout<<lie<<' '<<n-hang+1;
	}
	return 0;
}