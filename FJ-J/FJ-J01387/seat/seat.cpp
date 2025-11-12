#include<bits/stdc++.h> 
using namespace std;
long long s[114514],st[114][114],a,n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long b=n*m,c,I,q,p;
	for(int i=1;i<=b;i++)cin>>s[i];
	c=s[1];
	sort(s+1,s+b+1);
	for(int i=1;i<=b;i++){
		if(s[i]==c)I=i;
	}
	I=b-I+1;
	q=I/n,p=I%n;
	if(p>=1)q++;
	else p=n;
	if(I<=n){
		cout<<"1 "<<I;
	}else if(q%2==0){
		cout<<q<<" "<<m-p+1;
	}else if(q%2==1){
		cout<<q<<" "<<p;
	}
	return 0;
}
