#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b,e,f;
bool cmp(int c,int d){
	return c>d;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdin);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	b=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			e=i;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			f++;
			if(f==e){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
