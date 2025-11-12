#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,k,s[10005],me,mk;
	cin>>n>>m;
	k=n*m;
	//cout<<k<<" ";
	for(int i=1;i<=k;i++){
		long long a;
		cin>>a;
		s[i]=a;
		if(i==1)me=a;		
	}
	sort(s+1,s+1+k,cmp);
	for(int i=1;i<=k;i++){
		//cout<<s[i]<<" ";
		if(s[i]==me){
			mk=i;
			break;
		}
	}
	if(n==1){
		cout<<1<<" "<<mk;
		return 0;
	}
	//cout<<mk<<" ";
	long long ansx,ansy;
	//cout<<ansx<<" ";
	long long p=mk%n;
	ansx=mk/n;
	if(p==0)p=n;
	else if(p>0)ansx++;
	
	//cout<<p<<" ";
	if(ansx%2==0){
		ansy=m-p+1;	
	}
	else{
		ansy=p;
	}
	cout<<ansx<<" "<<ansy;
	return 0;
}
