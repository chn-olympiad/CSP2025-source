#include<bits/stdc++.h>
using namespace std;
int n,m,x,c;
vector<int> q;
int mapp[11][11];
bool sortt(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>c;
	q.push_back(c);
	for(int i=1;i<n*m;i++){
		cin>>x;
		q.push_back(x);
	}
	sort(q.begin(),q.end(),sortt);
	int k=0;
	for(int i=0;i<m;i++){
		int j;
		for(j=0;j<n;j++){
			mapp[j][i]=q[k];
			k++;
			if(mapp[j][i]==c){
				cout<<i+1<<" "<<j+1;
			}
		}
		i++;
		for(j=n-1;j>=0;j--){
			mapp[j][i]=q[k];
			k++;
			if(mapp[j][i]==c){
				cout<<i+1<<" "<<j+1;
				break;
			}
		}
	}
	return 0;
}
