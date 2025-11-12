#include<bits/stdc++.h>
using namespace std;
int n,m,R,c;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++) if(a[i]==R) c=i;
	int tmp1=c/n,tmp2=c%n;
	if(tmp2==0) 
		if(tmp1%2==0) cout<<tmp1<<' '<<1;
		else cout<<tmp1<<' '<<n;
	else{
		cout<<tmp1+1<<' ';
		if((tmp1+1)%2==0) cout<<n-tmp2+1;
		else cout<<tmp2;
	}
	return 0;
} 
