#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,xr,x,pm;
	cin>>a>>b;
	vector<int> zwh;
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			cin>>x;
			zwh.push_back(x);
		}	
	}
	xr=zwh[0];
	sort(zwh.begin(),zwh.end(),cmp);
	for(int i=0;i<zwh.size();i++){
		if(zwh[i]==xr){
			pm=i;
			break;
		}
	}
	int wzh,wzl;
	if(pm==0){
		cout<<1<<" "<<1;
		return 0;
	}
	wzl=pm/b;
	wzh=pm%b;
	if(wzl%2==0){
		cout<<wzl+1<<" "<<wzh+1;
	}else{
		cout<<wzl+1<<" "<<a-wzh;
	}
	return 0;
} 
