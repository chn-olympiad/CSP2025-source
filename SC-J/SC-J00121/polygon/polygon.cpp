#include<bits/stdc++.h>
using namespace std;
int china[5005];
int main(){
	freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int vui=1;vui<=n;vui++) scanf("%d",&china[vui]);
	sort(china+1,china+n+1);
	if(n==3){
		if(china[1]+china[2]<=china[3]){
			cout<<0;
		}
		else{
			cout<<1;
		}
	}
	return 0;
}