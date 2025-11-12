#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],wz;
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>a[i];
	int xr=a[0];
	sort(a,a+n*m);
	reverse(a,a+n*m);
	for(int i=0;i<n*m;i++){
		if(a[i]==xr){
			wz=i;
			break;
		}
	}
	int hang=wz/n+1;
	if(hang%2!=0){
		cout<<hang<<" "<<wz%n+1;
	}
	else{
		cout<<hang<<" "<<n-(wz%n);
	}
	return 0;
}
/*
hua-love×¨Êô
hua-love ´óÀÐorz 
*/
