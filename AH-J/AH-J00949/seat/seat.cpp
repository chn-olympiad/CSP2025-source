#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],t,s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	for(int i=1;i<=s;i++)cin>>a[i];
	t=a[1];
	sort(a+1,a+1+s);
	for(int i=1;i<=s;i++){
		if(a[i]==t){
			i=s+1-i;
			int c=i/n+1,mo=i%n;
			if(mo==0)c--;
			cout<<c<<' ';
			if(c%2==1){
				if(mo==0)cout<<n;
				else cout<<mo;
			}else {
				if(mo==0)cout<<1;
				else cout<<n+1-mo;
			}return 0;
		}
	}
}
