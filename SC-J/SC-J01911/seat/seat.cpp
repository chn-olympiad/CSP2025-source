#include<bits/stdc++.h>
using namespace std;
using ll=long long;
bool cmp(int a,int b){
	return a>=b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	int n,m,id,ansx,ansy;
	cin>>n>>m;
	vector<int> a(n*m);
	for(int i=0;i<m*n;i++){
		cin>>a[i];
	}
	id=a[0];
	sort(begin(a),end(a),cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==id){
			ansy=i/n;
			if(ansy%2==0){
				ansx=i%n+1;
			}else{
				ansx=n-i%n;
			}
		}
	}
	cout<<ansy+1<<" "<<ansx;
	return 0;
}