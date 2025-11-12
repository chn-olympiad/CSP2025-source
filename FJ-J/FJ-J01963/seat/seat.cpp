#include<bits/stdc++.h>
using namespace std;
int a[110];
int n,m,num;
int x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>a[i];
    	if(a[i]>a[1])  num++;
	}
    x=num/m;
    y=num%m;
    if(x%2==0)  cout<<x+1<<" "<<y+1<<endl;
    else  cout<<x+1<<" "<<n-y<<endl;
	return 0;
}
