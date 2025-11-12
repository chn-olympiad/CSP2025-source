#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1005],ansi=1,ansj=1,jrw;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	if(n==1&&m==1){
		cout<<1<<" "<<1;
		return 0;
	}
	int x=n*m;
	for(int i=1;i<=x;i++){
		cin>>a[i];
	}
	int jr=a[1],jrw=1;
	sort(a+1,a+x+1);
	for(int i=x;i>=1;i--){
		if(a[i]==jr){
			jrw=i;
			break;
		}
	}
	if(n==1){
		cout<<"1 "<<x-jrw+1;
		return 0;
	}
	if(m==1){
		cout<<x-jrw+1<<" 1";
		return 0;
	}
	cout<<ansi<<" "<<ansj;
	return 0;
}

