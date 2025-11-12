#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	vector<long long> a(n*m+1);
	long long ii=1;
	cin>>a[0];
	for(long long i=1;i<n*m;i++){
		cin>>a[i];
		if(a[i]>a[0])ii++;
	}
	
	long long q=ii/n,w=ii%n;
	if(w)q++;
	bool qq=q%2;
	long long ww;
	if(qq){
		ww=w;
		if(ww==0)ww=n;
	}
	else {
		if(w==0)w=1;
		ww=n-w+1;
	}
	cout<<q<<" "<<ww;
	return 0;
}