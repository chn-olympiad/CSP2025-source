#include<bits/stdc++.h>
using namespace std;
int n,m,p,a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	p=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==p){
			cout<<(i-1)/n+1<<" ";
			if(((i-1)/n+1)%2==0)
				cout<<n-(i-1)%n<<endl;
			else
				cout<<(i-1)%n+1<<endl;
			return 0;
		}
}
