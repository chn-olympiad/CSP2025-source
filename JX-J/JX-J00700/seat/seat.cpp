#include <bits/stdc++.h>
using namespace std;
int n,m,a[103],scr,num,c=1,r=1,cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	scr=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==scr){
			num=i;
			break;
		}
	}
	while(++cnt<=num){
		if((c&1)&&(r<n)) r++;
		else if(!(c&1)&&(r-1)) r--;
		else if(((c&1)&&(r==n))||(!(c&1)&&(r==1))) c++;
	}
	cout<<c<<' '<<r<<'\n';
	return 0;
}
