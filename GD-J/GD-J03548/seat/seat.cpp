#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],flag;
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)flag=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int i=1,j=1,k=1;
	while(k<=n*m){
		if(a[k]==flag){
			cout<<j<<' '<<i;
			return 0;
		}
		if((j%2!=0&&i==n)||(j%2==0&&i==1))j++;
		else if(j%2!=0)i++;
		else if(j%2==0)i--;
		k++;
	}
	return 0;
}
