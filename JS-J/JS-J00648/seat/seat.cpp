#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int p=a[1];
	sort(a+1,a+n*m+1);
	int x=1,y=1,f=0;
	//for(int i=1;i<=n*m;i++) cout<<a[i]<<" ";
	//cout<<endl;
	for(int i=n*m;i>=1;i--){
		if(a[i]==p){
			cout<<y<<" "<<x;
			break;
		}
		if(x+1>n&&f==0) y++,f=1;
		else if(x-1<1&&f==1) y++,f=0;
		else{
			if(f==1) x--;
			else x++;
		}
		//cout<<x<<" "<<y<<" "<<f<<endl;
	}
	return 0;
}
