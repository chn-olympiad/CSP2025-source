#include<bits/stdc++.h>
using namespace std;
int n,m,t,x=0,y=1;
int a[1000];
bool f;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	f=true;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(a[i]!=i){
			f=false;
		}
	}
	t=a[1];
	if(n==1&&m==1){
		cout<<1<<" "<<1;
		return 0;
	}
	if(f){
		cout<<m<<" "<<n;
		return 0;
	}
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(y%2!=1&&x==1){
			y++;
		}
		else if(y%2==1&&x==n){
			y++;
		}
		else{
			if(y%2==1){
				x++;
			}
			else{
				x--;
			}
		}
	//	cout<<x<<" "<<y<<endl;
		if(a[i]==t){
			cout<<y<<" "<<x;
			break;
		}
	}
	return 0;
}
