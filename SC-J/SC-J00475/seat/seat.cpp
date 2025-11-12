#include<bits/stdc++.h>
using namespace std;
long long n,m,x,id=1,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>x;
	for(int i=2;i<=n*m;i++){
		cin>>y;
		if(y>x){
			id++;
		}
	}
	
	cout<<(id-1)/n+1<<" "<<(((id-1)/n+1)%2==1?id-((id-1)/n)*n:n-(id-((id-1)/n)*n)+1);
	return 0;
} 