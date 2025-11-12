#include<bits/stdc++.h>
using namespace std;
int a[205];
int t,s;
int n,m;
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	t=a[1];
	const int N=n*m;
	sort(a+1,a+1+N,cmp);
	for(int i=1;i<=N;i++){
		if(a[i]==t){
			s=i;
			break;
		}
	}
	int n1=(s-1)/n;//ап
	n1++;
	if(n1%2==1) cout<<n1<<" "<<(s-1)%n+1<<endl;
	else cout<<n1<<" "<<n-(s-1)%n<<endl;
}
