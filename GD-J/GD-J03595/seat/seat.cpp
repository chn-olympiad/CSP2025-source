#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n*m);
	int s,toul;
	for(int i=0;i<n*m;i++){
		cin>>s;
		if(i==0) toul=s;
		a.push_back(s);
	}
	sort(a.begin(),a.end());
	int o=a.size()-1;
	bool e=false;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[o]==toul){
					cout<<i<<" "<<j;
					e=true;
				}
				o--;
			}
		}else{
			for(int j=n;j>0;j--){
				if(a[o]==toul){
					cout<<i<<" "<<j;
					e=true;
				}
				o--;
			}
		}
		if(e) break;
	} 
	return 0;
} 
