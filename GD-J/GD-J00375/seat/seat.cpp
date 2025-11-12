#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> a;
bool cmp(int a,int b){
	return a>b;
}
pair<int,int> sat[105];
int msco;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x;
			cin>>x;
			a.push_back(x);
		}
	}
	msco=a[0];
	sort(a.begin(),a.end(),cmp);
	int x=1,y=1;
	for(int i=0;i<a.size();i++){
		sat[a[i]]={x,y};
		if(y%2==1){
			x+=1;
			if(x>n){
				x=n;
				y+=1;
			}
		}
		else{
			x-=1;
			if(x<1){
				y+=1;
				x=1;
			} 
		}	
	}
	cout<<sat[msco].second<<" "<<sat[msco].first;
	
	
	return 0;
}
