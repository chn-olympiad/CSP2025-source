#include<iostream>
using namespace std;
int a[105];
int t[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	for(int i=1;i<=n*m;i++){
		t[a[i]]=true;
	}
	for(int i=100;i>=0;i--){
		if(t[i]==true) a[++a[0]]=i;
	}
	int index;
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			index=i;
			break;
		}
	}
	if(index%(2*n)==0) cout<<index/n<<" "<<1;
	else if(index%(2*n)<=n) cout<<index/(2*n)*2+1<<" "<<index%(2*n);
	else cout<<index/(2*n)+2<<" "<<n-index%n+1;
	return 0;
}

