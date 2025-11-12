#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int x=n*m;
	int u,s;
	vector<int> a;
	if(m==1&&n==1){
		cin>>u;
	    cout<<u;
		return 0;
	}
	for(int i=1;i<=x;i++){
		cin>>u;
		if(i==1){
			s=u;
		}
		a.push_back(u);
	}
	
	int ni=1,mi=1;
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
    for(auto c:a){
    	if(c==s){
    		cout<<mi<<" "<<ni;
		}
		else{
			ni++;
			if(ni>n){
				ni=1;
				mi++;
			}
		}
	}
	return 0;
}
