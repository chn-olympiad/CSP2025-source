#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],spe,sped,ii;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);//让优化助我一臂之力 
    cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int si=n*m;
	for(int i=1;i<=si;i++){
		cin>>a[i];
	}
	spe=a[1];
	sort(a+1,a+si+1);
	for(int i=si;i>=1;i--){
		ii++;
		if(a[i]==spe){
			sped=ii;
			break;
		}
	}
	int c=ceil(1.0*sped/n);
	int mo=sped%n;
	if(mo==0 && c%2==1){
		cout<<c<<" "<<n;
		return 0;
	}
	if(mo==0 && c%2==0){
		cout<<c<<" "<<1;
		return 0;
	}
	if(c%2==1){
		cout<<c<<" "<<mo;
		return 0;
	}
	if(c%2==0){
		cout<<c<<" "<<n-mo+1;
	}
	return 0;
}
