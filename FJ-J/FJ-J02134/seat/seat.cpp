#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105],ans[15][15];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int s=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			s=i;
			break;
		}
	}
	int k=s%m;
	if(s%m==0){
		s/=m;
	}else{
		s=s/m+1;
	}
	cout<<s<<" ";
	if(s%2==1){
		if(k==0){
			k+=n;
		}
		cout<<k;
	}else{
		cout<<n-k;
	}
	return 0;
} 
