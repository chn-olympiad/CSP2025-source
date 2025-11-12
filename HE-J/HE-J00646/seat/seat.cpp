#include<bits/stdc++.h>
using namespace std;
int a[10005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);	
	freopen("seat.out","w",stdout);
	int n,m;
	int s;
	cin>>n>>m;
	cin>>s;
	a[1]=s;
	int b=1;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			b++;
		}
	}
//	cout<<b<<endl;
	if(b==1){
		cout<<1<<' '<<1;
		return 0;
	}
	if(((b-1)/n+1)%2==1){
		cout<<(b-1)/n+1<<" "<<(b-1)%n+1;
	}
	else{
		cout<<(b-1)/n+1<<" "<<n-((b-1)%n+1)+1;
	}
	return 0;
}
