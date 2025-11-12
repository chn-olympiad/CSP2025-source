#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> v(n*m);
	for(int i=0;i<n*m;i++){
		cin>>v[i];
	}
	int num=v[0];
	int d;
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<n*m;i++){
		if(v[i]==num){
			d=i+1;
			break;
		}
	}
	int x=d/n;
	int y;
	if(d%n==0){
		if(x%2==0){
			y=1;
		}else{
			y=n;
		}
	}else{
			x++;
			y=d%n;
			if(x%2==0){
				y=n-y+1;
			}
	}
	cout<<x<<" "<<y;
	return 0;
}
