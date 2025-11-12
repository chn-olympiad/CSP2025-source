#include<bits/stdc++.h>
using namespace std;
int vis[15][15];
vector<int> s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int a;
	a=m*n;
	for(int k=1;k<=a;k++){
		cin>>s[k];
	}
	int ans;
	int siz=s.size();
	for(int i=1;i<=siz;i++){
		ans=s[i];
	}
	sort(s.end(),s.begin());
	for(int i=1;i<=siz;i++){
		if(s[i]==ans){
			if(i%n==0) cout<<i/n<<" ";
			else cout<<i/n+1<<" ";
			if(i%m==0) cout<<m;
			else cout<<i%m;
		}
	}
	return 0;
}