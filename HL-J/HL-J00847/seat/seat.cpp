#include <bits/stdc++.h>
using namespace std;
struct node{
	int b;
}a[1000000];
int n,m;
bool cmp(node a,node c){
	return a.b>c.b;
}
int v[1000][1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].b;
	}
	int yu=a[1].b;
	sort(a+1,a+n*m+1,cmp);
	int cnt=1;
	for(int i=1;i<=n*m;i++){
		if(a[i].b==yu){
		  cnt=i;
		  break;
		}
	}
	if((cnt/n)%2==1){
		if(cnt%n!=0){
			cout<<cnt/n+1<<" "<<n-cnt%n+1;
			return 0;
		}
		else{
			cout<<cnt/n<<" "<<n;
			return 0;
		}
	}
	else if(cnt/n==0){
		cout<<1<<" "<<cnt;
	}
	else{
		if(cnt%n!=0){
			cout<<cnt/n+1<<" "<<cnt%n;
			return 0;
		}
		else{
			cout<<cnt/n<<" "<<1;
			return 0;
		}
	}
	return 0;
}







