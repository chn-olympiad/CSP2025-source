#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int r;
	cin>>r;
	int wei=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(j==0&&i==0)continue;
			int x;
			cin>>x;
			if(x>r)wei++;
		}
	}
	int hang=(wei-1)%n+1;
	int lie=wei/n+(wei%n!=0);
	if(lie%2==0){
		hang=n+1-hang;
	}
	cout<<lie<<" "<<hang;
	return 0;
}

