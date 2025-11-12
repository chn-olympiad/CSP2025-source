#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	vector<int> a(n*m);
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
	}
	
	int r=a[1];
	sort(a.begin()+1,a.end(),cmp);
	for(int i=1;i<=n*m;++i){
		if(a[i]==r){
			r=i;
			break;
		}
	}
	
	int ls=(r%n==0)?r/n:r/n+1;


	int jl=r%n;
	if(r%n==0){
		jl=(ls%2==0)?1:n;
	}
	else{
		jl=(ls%2==0)?n-jl+1:jl;
	}
	
	cout<<ls<<" "<<jl<<endl;
	
	return 0;
}


