#include <bits/stdc++.h>
using namespace std;
vector<int> v;
bool cmp(int a1,int b1){return a1>b1;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,x=1,y=1;
	cin>>n>>m>>a;
	for(int i=0;i<n*m-1;i++){
		int t;
		cin>>t;
		v.push_back(t);
	}
	v.push_back(a);
	sort(v.begin(),v.end(),cmp);
	for(int i:v){
		if(i==a){
			cout<<x<<' '<<y;
			break;
		}
		if(x%2) y++;
		else if(x%2==0) y--;
		
		if(y>n) y=n,x++;
		else if(y<1) y=1,x++;
		
	}
	return 0;
}

