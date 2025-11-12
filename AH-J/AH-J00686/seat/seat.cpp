#include<bits/stdc++.h>
using namespace std;
int n,m,a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int x=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	int i=1,j=1,cnt=0,f=1;
	while(cnt<n*m){
		if(i>n){
			i=n;
			j++;
			f=2;
		}
		if(i<1){
			i=1;
			j++;
			f=1;
		}
		cnt++;
		if(a[cnt]==x){
			break;
		}
		if(f==1) i++;
		else i--; 
	}
	cout<<j<<" "<<i<<endl;
	return 0;
}
