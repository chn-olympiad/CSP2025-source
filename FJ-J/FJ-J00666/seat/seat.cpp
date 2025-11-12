#include<bits/stdc++.h>
using namespace std;
long long n,m;
priority_queue<long long>q;
long long seat[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	int st;
	cin>>st;
	q.push(st);
	for(int i=2;i<=n*m;i++){
		long long a;
		cin>>a;
		q.push(a);
	}
	long long x=1,y=1;
	long long fb=1;
	while(!q.empty()){
		long long ans=q.top();
		q.pop();
		if(ans==st){
			cout<<x<<" "<<y<<endl;
			break;
		}
		if(y==n&&fb==1){
			x++;
			fb=-1;
			continue;
		}else if(y==1&&fb==-1){
			x++;
			fb=1;
			continue;
		}
		y+=fb;
	}
	return 0;
}

