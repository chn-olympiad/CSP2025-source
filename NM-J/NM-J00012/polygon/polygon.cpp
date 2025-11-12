#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    if(n<3){
		cout<<0;
	}
	long long sum=0,nmax=-1;
	long long a[5005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		nmax=max(nmax,a[i]);
	}
	if(sum>nmax)cout<<1;
	else cout<<0;
    return 0;
}
/*
 * 约100+100+40+40=280吧
	最低……，不知道……
	燃尽了……
	qwq
	AK,IOI!!
	while(1) rp++;
*/
