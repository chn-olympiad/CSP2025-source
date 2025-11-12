#include<bits/stdc++.h>
using namespace std;

int n,m;
int nx=1,ny=1;
bool flag=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int sum=n*m,f;
	vector<int>ve(sum,0);
	for(int i=1;i<=sum;i++){
		cin>>ve[i];
	}
	if(n==1&&m==1){
		cout<<"1 1";
		return 0;
	}
	f=ve[1];
	priority_queue<int>q(ve.begin(),ve.end());
	for(int i=1,p;i<=n;i++){
		p=q.top();
		q.pop();
		ve[i]=p;
	}
	if(m==1||n==1){
		for(int i=1;i<=sum;i++){
		    if(ve[i]==f&&m==1) {
			    cout<<i<<" 1";
			    return 0;
			}
			if(ve[i]==f&&n==1) {
			    cout<<"1 "<<i;
			    return 0;
			}
		}  
	}
	for(int i=1;i<=sum;i++){
		if(ve[i]==f){
			cout<<nx<<" "<<ny;
			return 0;
		}
		if(ny==n||(ny==1&&nx!=1)){
		nx++;
			if(ny==1){
			flag=0;
		}else flag=1;
		}else{
			if(!flag) ny++;
			if(flag) ny--;
		}	
	}
	return 0;
}