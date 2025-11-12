#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,ans1=0,ans2,p=1,a,b;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=2;i<=n*m;i++){
		cin>>b;
		if(a<b)p++;
	}
	ans1=p/(2*n)*2;
	p=p%(2*n);
	if(p==0)ans2=1;
	else if(p<=n){ans1++;ans2=p;}
	else {ans1+=2;ans2=n-(p-n)+1;}
	cout<<ans1<<" "<<ans2;
	return 0;
}//97997889876886765788756677878956856785678965yurtuyiugrfguirduiurgtuirtguirtgui他
