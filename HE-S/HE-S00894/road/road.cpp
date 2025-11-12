#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,m,k,w;
int u[3];
int sam=n*m*k;
int main(){
	freopen("road.txt","r",stdin);
	freopen("road.out","w",stdout);
	cin>>u[1]>>u[2]>>u[3];
	int cnt=min(u[0],min(u[1],u[2]));
	for(int i=0;i<n;i++){
		cin>>u[i];
	}
	if(sam==cnt){
		cout<<sam;
	}else{
		cout<<sam-1;
	}
	int q;
	cin>>q;
	int dak=q*k;
	cout<<sam<<dak<<endl;
	return 0;
}
