#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10005],s,num,mod,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(s==a[i]){
			num=n*m-i+1;
			break;
		}
	}
	mod=num/n;
	y=num-mod*n;
	if(y==0){
		if(mod%2==0){
			cout<<mod<<" "<<"1";
		}
		else{
			cout<<mod<<" "<<n;
		}
	}
	else{
		if(mod%2==0){
			cout<<mod+1<<" "<<y;
		}
		else{
			cout<<mod+1<<" "<<n-y+1;
		}
	}
	return 0;
}

