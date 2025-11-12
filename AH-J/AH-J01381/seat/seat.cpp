#include<bits/stdc++.h>
using namespace std;
int n,m,t,c,r;
vector<int> a;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>t;
		a.push_back(t);
	}
	t=a[0];
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<(int)a.size();i++){
		if(a[i]==t){
			t=i+1;
			break;
		}
	}
	c=t/n+1;
	r=t%m;
	if(t%n==0) c--;
	if(r==0) r=m;
	if(c%2==0) r=m-r+1;
	cout<<c<<" "<<r<<endl;
	return 0;
}
