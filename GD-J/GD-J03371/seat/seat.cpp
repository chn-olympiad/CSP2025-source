#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,his_score,pos;
	cin>>n>>m;
	vector<int>a(n*m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i*m+j];
		}
	}
	his_score=a[0];
	sort(a.begin(),a.end());
	pos=lower_bound(a.begin(),a.end(),his_score)-a.begin();
	pos=n*m-pos-1;
	if((pos/n)%2==0){
		//No.1,3,5,7,9,...
		cout<<pos/n+1<<" "<<pos%n+1;
	}else{
		//No.2,4,6,8,...
		cout<<pos/n+1<<" "<<n-pos%n;
	}
	return 0;
}
