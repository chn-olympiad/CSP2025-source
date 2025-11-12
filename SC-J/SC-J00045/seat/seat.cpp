#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,a[105],k;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cnt=n*m;
	for(int i=1;i<=cnt;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		if(a[i]==k){
			k=i;
			break;
		}
	}
	if(k%n==0){
		cout<<k/n<<" ";
		if((k/n)%2==0){
			cout<<1;
		}
		else cout<<n;
	}
	else{
		cout<<k/n+1<<" ";
		if((k/n)%2==0){
		    cout<<k%n;	
		}
		else cout<<n-k%n+1;
	} 
	return 0;
}