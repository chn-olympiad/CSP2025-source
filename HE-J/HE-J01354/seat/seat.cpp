#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int c,r,R;//cÁÐ rÐÐ
	cin>>c>>r;
	vector<int>v(c*r);
	for(int i=0;i<=c*r-1;i++)cin>>v[i];
	R=v[0];
	sort(v.rbegin(),v.rend());
	int c1,r1,n;
	for(int i=0;i<v.size();i++){
		if(R==v[i]){
			n=i+1;
			break;
		}
	}
	if(n%r){
		c1=n/r+1;
	
	}
	if(n%r==0){
		c1=n/r;
	}
	if(n%r&&c1%2){
		r1=n%r;
	}
    if(n%r==0&&c1%2){
		r1=r;
	}
	if(n%r&&c1%2==0){
		r1=r-n%r+1;
	}
	if(n%r==0&&c1%2==0){
		r1=1;
	}

	cout<<c1<<" "<<r1;
	return 0;
}
