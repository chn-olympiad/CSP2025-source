#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	if(a>b)return 1;
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,an,am;
	cin>>n>>m;
	int scr[n*m];
	for(int i=0;i<n*m;i++)cin>>scr[i];
	int tmp=scr[0],pm;
	sort(scr,scr+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(tmp==scr[i]){
			pm=i;break;
		}
	}
	am=pm/n+1;
	if(am%2) an=pm%n+1;
	else an=n-pm%n;
	cout<<am<<" "<<an;
	return 0;
}
