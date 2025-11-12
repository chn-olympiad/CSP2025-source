#include<bits/stdc++.h>
using namespace std;
int a[105],b[105],n,t[105],m,s,o,e=0,s2,p,q;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	o=n*m;
   q=n*m;
	for(int i=1;i<=o;i++)
	cin>>t[i];
	s=t[1];
	sort(t+1,t+o+1);
	for(int i=1;i<=o;i++){
		a[q--]=t[i];
	}
	for(int i=1;i<=o;i++){
	if(a[i]==s)s2=i;
	}
	p=ceil(s2*1.0/n);
	if(p%2==0){
	for(int i=p*n;i>=(p-1)*n+1;i--){
			b[++e]=a[i];
			if(i==s2)s2=e;
		}
		cout<<p<<" "<<s2;
	}
	else{
		for(int i=(p-1)*n+1;i<=p*n;i++){
		b[++e]=a[i];
		if(i==s2)s2=e;
		}
		cout<<p<<" "<<s2;
			}
		return 0;
}


