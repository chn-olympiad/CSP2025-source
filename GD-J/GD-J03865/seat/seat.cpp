#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int number[105];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin) ;
	freopen("seat.out","w",stdout) ;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>number[i];
	int R=number[0],ri;
	sort(number,number+n*m+1,cmp);
	for(int i=0;i<n*m;i++){
		if(number[i]==R){
			ri=i+1;
			break;
		}
	}
	//cout<<ri<<endl;
	int h,l;
	l=ceil(ri*1.0/n);
	if(l%2){
		h=ri-(l-1)*n;
	}
	else{
		h=n-(ri-(l-1)*n)+1;
	}
	cout<<l<<" "<<h;
	return 0;
}
