#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int a[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int cnt=a[1];
	sort(a+1,a+n*m+1,cmp);
	int q;
	for(int i=1;i<=n*m;i++){
		if(a[i]==cnt){
			q=i;
			break;
		}
	}
	if(q%(2*n)==n)cout<<q/n<<' '<<n<<endl;
	else if(q%(2*n)==0)cout<<q/n<<' '<<1<<endl;
	else if(q%(2*n)<n)cout<<q/n+1<<' '<<q%n<<endl;
	else cout<<q/n+1<<' '<<n-q%n+1<<endl;
	return 0;
}