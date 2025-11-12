#include<bits/stdc++.h>
using namespace std;
int a[110],n,m; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++) cin>>a[i];
	int R=a[0]; 
	sort(a,a+n*m,greater<int>());
	int j=1,i=1,fl=1;
	bool flag=0;
	for(int s=0;s<n*m;s++){
		if(a[s]==R) break;
		if((i==n||(i==1&&s>0))&&(!flag)){
			j++;
			fl=-fl;
			flag=1;
		}
		else {
			flag=0;
			i+=fl;
		}
	}
	cout<<j<<' '<<i;
	return 0;
}
