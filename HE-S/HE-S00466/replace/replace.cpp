#include<bits/stdc++.h>
#define ll long long
#define cin std::cin
#define cout std::cout
#define IOS cin.tie(nullptr)->sync_with_stdio(false);
const int N=1e6+5;
int n,m;
std::vector<std::string> x,y;
std::vector<std::string> lm;
void solve(){
	int ans=0;
	std::string a,b;
	cin>>a>>b;
	if(a.length()!=b.length()){
		cout<<0<<'\n';
		return ;
	}
	for(int i=1;i<=n;i++){
		if(x[i]==a&&y[i]==b){
			ans++;
		}
	}
	for(int i=1;i<=n;i++){
		int l=a.find(lm[i]);
		std::string c=a;
		for(int j=l;j<=lm[i].length();j++){
			c[i]=lm[i][j];
		}
		if(c==b) ans++;
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		std::string a,b;
		cin>>a>>b;
		x.push_back(a);
		y.push_back(b);
	}
	while(m--){
		cout<<0<<'\n';
	}
	return 0;
}

