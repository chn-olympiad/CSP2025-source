#include<bits/stdc++.h>
using namespace std;

int a[110];

bool cmp(const int &x,const int &y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	int i=1,tot=0;
	int j=1;
	while(tot<=n*m){
		tot++;
		if(a[tot]==k){
			cout<<j<<' '<<i;
			return 0;
		}
		if(i==n&&j%2!=0) j++,i=n;
		else if(i==1&&j%2==0) j++,i=1;
		else if(j%2!=0) i++;
		else if(j%2==0) i--;
	}
		
	return 0;
}
