#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y,a[105],mm=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			mm++;
		}
	}
	int b=n*2;
	int cnt=mm%b;
	if(cnt==0){
		cnt=b;
	}
	x=(mm-cnt)/n+1;
	if(cnt>n){
		x++;
		int g=cnt-n;
		y=n-g+1;
	}else{
		y=cnt;
	}
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
