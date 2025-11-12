#include<bits/stdc++.h>
using namespace std;
string a[200010][2];
int t[200010];
bool check(int now,int lo,string who,string which){
	for(int i = now; i<now + lo; i++){
		if(who[i] != which[i-now]){
			return false;
		}
	}
	return true;
}
string change(int now,int lo,string who,string which){
	for(int i = now; i< now + lo; i++){
		who[i] = which[i-now];
	}
	return who;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i = 1; i<=n; i++){
		cin>>a[i][0] >>a[i][1];
		t[i] = a[i][0].size();
	}
	while(q--){
		int ans = 0;
		string x,y;
		cin>>x>>y;
		int l = x.size();
		for(int i = 1; i<= n; i++){
			
			for(int j = 0; j <= l - t[i]; j++){
				string xy = x;
				if(check(j,t[i],xy,a[i][0])){
					xy = change(j,t[i],xy,a[i][1]);
					if(xy == y){
						ans++;
					}
				}
			} 
		}
		cout<<ans<<endl;
	}
	return 0;
}
