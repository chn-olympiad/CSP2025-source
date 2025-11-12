#include<bits/stdc++.h>
using namespace std;
int n,m,r;
vector<int> scores;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin>>n>>m;
	cin>>r;
	for(int i = 1;i<n*m;i++){
		int x;
		cin>>x;
		scores.push_back(x);
	} 
	
	sort(scores.begin(),scores.end(),cmp);
	
	int it = upper_bound(scores.begin(),scores.end(),r,greater<int>())-scores.begin()+1;
	
	
	int r;
	if(it%n == 0) r = it/n;
	else r = it/n+1;
	int c; 
	
	if(r%2 == 0){
		c = m-(it-(r-1)*m)+1;
	}else{
		c = it-(r-1)*m;
	}
	
	cout<<r<<" "<<c;
	
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
