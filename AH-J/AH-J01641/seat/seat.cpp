#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
	return x>y;
}
	long long n,m,s,ns,a,b;
	vector <long long> num;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		long long in;
		cin>>in;
		if(i==0)s=in;
		num.push_back(in);
	}
	//cout<<num.begin()-num.end()<<endl;
	sort(num.begin(),num.end(),cmp);
	for(int i=0;i<num.end()-num.begin();i++){
		if(num[i]==s)ns=i+1;
	}
	a=ns/n;
	if((double)ns/(double)n!=a)a++;
	b=ns%n;
	if(!b)b=n;
	//cout<<"ns="<<ns<<"a="<<a<<"b="<<b<<endl;
	cout<<a<<' ';
	if(a%2==0)cout<<m-b+1;
	else cout<<b;
	return 0;
}
