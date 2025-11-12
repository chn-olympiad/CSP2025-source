#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
priority_queue<int,vector<int>,less<int> >q;
int a;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	q.push(a);
	for(int i=1;i<n*m;i++){
		int x;
		cin>>x;
		q.push(x);
	}
	int c=1,r=1;
	for(int i=1;;i++){
		int x=q.top();
		q.pop();
		if(a==x){
			cout<<c<<" "<<r;
			break;
		}else{
			if(c%2==1){
				r++;
				if(r>n){
					c++,r=n;
				}
			}else{
				r--;
				if(r<1){
					c++,r=1;
				}
			}
		}
	}
	return 0;
}
