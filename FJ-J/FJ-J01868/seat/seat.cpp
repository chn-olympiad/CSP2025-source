#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],aaa;
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
	aaa=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==aaa){
			aaa=i;
			break;
		}
	}
	if(aaa%n==0){
		if((aaa/n)%2==1){
			cout<<aaa/n<<" "<<n;
		}else{
			cout<<aaa/n<<" 1";
		}
		return 0;
	}
	if(((aaa-aaa%n)/n+1)%2==0){
		cout<<(aaa-aaa%n)/n+1<<" "<<n-aaa%n+1;
	}else{
		cout<<(aaa-aaa%n)/n+1<<" "<<aaa%n;
	}
	return 0;
}
