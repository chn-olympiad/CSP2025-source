#include <bits/stdc++.h>
using namespace std;
int m,cnt=0,cnth;
double maxsum=1,n=1;
int l,h;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>cnt;
	for(int i=2;i<=n*m;i++){
		int cnt1;
		cin>>cnt1;
		if(cnt1>cnt){
			maxsum++;
		}
	}
	if(double(maxsum/n)>int(maxsum/n)){
		l=int(maxsum/n)+1;
	}
	else{
		l=maxsum/n;
	}
	cnth=int(maxsum)%int(n);
	if(cnth==0){
		cnth=n;
	}
	if(l%2==0){
		h=n-cnth+1;
	}
	else{
		h=cnth;
	}
	cout<<l<<" "<<h<<endl;
	return 0;
}
