#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int y=a[1],x=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==y){
			x=i;
			break;
		}
	}
	if(x%n==0){
		if((x/n%2)==1){
			cout<<x/n<<" "<<n;
		}else{
			cout<<x/n<<" "<<1;
		}
	}else{
		if((x/n+1)%2==1){
			cout<<x/n+1<<" "<<x%n;
		}else{
			cout<<x/n+1<<" "<<n-(x%n)+1;
		}
	}
	return 0;
} 
