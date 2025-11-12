#include<bits/stdc++.h>
using namespace std;
long long m,n,r,f,s=1,g;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>r;//h l
	for(int i=1;i<=n*m-1;i++){
		cin>>f;
		if(f>r)s++;
	}
	if(m==1){//l h
		cout<<1<<" "<<s;
		return 0;
	}
	if(n==1){//l h
		cout<<s<<" "<<1;
		return 0;
	}
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int o=1;o<=n;o++){
				g++;
				//cout<<i<<" "<<o;
				if(g==s){
					cout<<i<<" "<<o;
					return 0;
				}	
			}
		}else{
			for(int o=n;o>=1;o--){
				g++;
				//cout<<i<<" "<<o;
				if(g==s){
					cout<<i<<" "<<o;
					return 0;
				}	
			}
		}
	}
	return 0;
}
