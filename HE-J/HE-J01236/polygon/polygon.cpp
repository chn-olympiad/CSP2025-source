#include<bits/stdc++.h>//PAC
using namespace std;
#define _ long long
_ n,l[5005],cnt;
int main(){//input
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
	cin>>l[0]>>l[1]>>l[2];
	if(l[0]+l[1]+l[2]>max(l[0],max(l[1],l[2]))*2){
		cout<<1;
	}else cout<<0;
	}else for(_ i=0;i<n;i++){
		cin>>l[i];
		if(l[i])cnt++;
	}cout<<cnt;
	return 0;
}

