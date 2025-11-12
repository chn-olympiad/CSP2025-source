#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int> > s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int ttl=n*m;
    int R;
    cin>>R;
    s.push(R);
    int numr;
    for(int i=1;i<ttl;i++){
    	int x;
    	cin>>x;
    	s.push(x);
	}
	for(int i=0;i<ttl;i++){
		int x=s.top();
		s.pop();
		if(x==R){
			numr=i+1;
			break;
		}
	}
	int c=(numr+(n-numr%n))/n;
	int r;
	if(numr%n==0){
		c--;
	}
	if(c%2==0){
		r=n-(numr-1)%n;
	}
	else{
		r=numr%n;
		if(numr%n==0){
			r=n;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
