#include<bits/stdc++.h>
using namespace std;
bool cmp(short x,short y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[105];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int R=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			if(i%n!=0){
				cout<<i/n+1<<" ";
				if((i/n)%2==1)cout<<n-(i%n)+1;
				else cout<<i%n;
			}
			else{
				cout<<i/n<<" ";
				if((i/n)%2==1)cout<<n;
				else cout<<1;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
