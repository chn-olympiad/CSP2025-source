#include<bits/stdc++.h>
using namespace std;
long long n,m,c,r,len,t,sc;
vector<int> a;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	len=n*m;
	for(int i=0;i<len;++i){
		cin>>t;
		a.push_back(t);
	}
	sc=a[0];
	sort(a.begin(),a.end());
	for(t=0;t<len;++t){
		if(a[t]=sc){
			break;
		}
	}
	t++;
	if(t%2==0){
		c=ceil(t/n)+1;
		r=n-(t%n)+1;
		cout<<c<<' '<<r;
	}else{
		c=ceil(t/n)+2;
		r=n-(t%n)+1;
		cout<<r<<' '<<c;
	}
	return 0;
}
