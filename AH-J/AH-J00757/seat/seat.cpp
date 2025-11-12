#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
	}
	long long xl=a[1];
	long long zb;
	sort(a+1,a+n*m+1,cmp);
	for(long long i=1;i<=n*m;i++){
		if(a[i]==xl){
			zb=i;
			break;
		}
	}
	long long c,d;
	c=zb/m;
	d=zb%m;
//	cout<<zb<<"c="<<c<<"d="<<d<<endl;
	if(c==0){
		cout<<1<<" ";
	}else{
		if(d!=0){
			cout<<c+1<<" ";
		}else{
			cout<<c<<" ";
		}
		
	}
	
	if(c%2==0){
		//cout<<"#######"<<endl;
		if(d==0){
			cout<<1;
		}
		else{
			cout<<d;
		}
	}else{
	//	cout<<"2^^^^^^^^^^^"<<endl;
		if(d==0){
			cout<<m;
		}else{
			cout<<m-d+1;
		}
	}
	return 0;
}

