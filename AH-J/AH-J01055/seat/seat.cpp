#include<bits/stdc++.h>
using namespace std;
int n,m,t;
vector<int> v;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		int t;
		cin>>t;
		v.push_back(t);
	}
	int r=v[0];
	sort(v.begin(),v.end());
	for(int i=n*m-1;i>=0;i--){
		if(v[i]==r){
			t=n*m-i;
		}
	}
	int x=1,y=1;
	bool b=true;
	if(t==1){
		cout<<1<<" "<<1;
		return 0;
	}
	for(int i=1;i<=t-1;i++){
		if(b){
			y++;
		}else{
			y--;
		}
		if(y>n){
			
			
			y=n;
			b=false;
			x++;
		}
		if(y<1){
			y=1;
			b=true;
			x++;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
