#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005];

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
	sort(a+2,a+1+n*m,cmp);
	int s=n*m;
	for(int i=2;i<=n*m;i++){
		if(a[1]>a[i]){
			s=i-1;
			break;
		}
	}
//	cout<<s<<endl;
	cout<<(s-1)/n+1<<" ";
	if(((s-1)/n+1)%2==0){
		if(s%n==0){
			cout<<1;
			return 0;
		}else{
			cout<<n-s%n+1;
			return 0;
		}
	}else{
		if(s%n==0){
			cout<<n;
			return 0;
		}else{
			cout<<s%n;
			return 0;
		}
	}
	
	return 0;
}
