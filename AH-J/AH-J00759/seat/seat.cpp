#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int tmp=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1,f=1,i=1;
	while(tmp!=a[i]){
		x+=f;
		if(x>n){
			x=n,y++,f=-1;
		}
		if(x<1){
			x=1,y++,f=1;
		}
		i++;
	}
	cout<<y<<" "<<x<<endl;
	return 0;         
}
