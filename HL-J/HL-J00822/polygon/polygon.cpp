#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,wpxbypc[114514];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>wpxbypc[i];
	}
	sort(wpxbypc+1,wpxbypc+n);
	if(n<3){
		cout<<0;
		return 0;
	}
	if(wpxbypc[1]+wpxbypc[2]<=wpxbypc[3]){
		cout<<0;
		return 0;
	}
	cout<<1;
	return 0;
}
