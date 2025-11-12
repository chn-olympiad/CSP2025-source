#include<bits/stdc++.h>
using namespace std;
const int N=150;
int a[N],b[N];
bool cmp(int A,int B){
	return A>B;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int t;
	for(int i=1;i<=n*m;i++){
		if(a[i]==b[1]){
			t=i;
			break;
		}
	}
	if(t%n==0){
		if((t/n)%2==0){
			cout<<t/n<<" "<<1;
		}else{
			cout<<t/n<<" "<<n;
		}
		return 0;
	}
	if((t/n)%2==0){
		cout<<(t/n)+1<<" "<<t%n;
		return 0;
	}
	if((t/n)%2==1){
		cout<<t/n+1<<" "<<n-t%n+1;
	}
	return 0;
}
