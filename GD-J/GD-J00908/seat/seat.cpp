#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[105],tmp,p,a1,a2;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	tmp=a[1];
	sort(a+1,a+1+(n*m),cmp);
	for(int i=1;i<=n*m+1;i++){
		if(tmp==a[i]){
			p=i;
			break;
		}
	}a1=((n-(p%n))+p)/n;
	if(p%m==0) a2=m;
	else a2=p%m;
	if(a1%2==0) a2=m-a2+1;
	cout<<a1<<" "<<a2<<endl;
}
