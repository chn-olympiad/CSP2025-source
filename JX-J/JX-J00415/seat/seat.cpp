#include<bits/stdc++.h>
using namespace std;
int a[1001],m,n,x,y,c;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	c=a[1];
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=m*n;i++){
		if(a[i]==c){
			c=i;
			break;
		}
		
	}
	if(((c-1)/n+1)%2==1)
	cout<<floor((c-1)/n)+1<<" "<<(c-1)%n+1;
	else{
		cout<<floor((c-1)/n)+1<<" "<<n-(c-1)%n;
	}
    return 0;
}
