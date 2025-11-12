#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=2000;
vector<int> a;
int n,m,p;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>p;
	a.push_back(-p);
	for(int i=2;i<=n*m;i++){
		int x;
		cin>>x;
		a.push_back(-x);
	}
	sort(a.begin(),a.end());
	int i=0;
	while(-a[i]!=p) i++;
	int c=i/n+1;
	int r=0;
	if(c%2==1){
		r=i%n+1;
	}else{
		r=n-i%n;
	}
	cout<<c<<' '<<r<<endl;
	return 0;
}
