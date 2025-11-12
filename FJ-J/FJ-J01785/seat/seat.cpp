#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10005],sz,l=1,ans=0;
bool cmp(int se,int sa){
	return se>sa;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>sz;
	a[1]=sz;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[l]==sz){
				ans=n*m-l;
				break;
			}
			l++;
		}
		if(ans){
			break;
		}
	}
	if(l%n==0){
		cout<<l/n<<" ";
		if((l/n)%2==1){
			cout<<n;
		}
		else{
			cout<<1;
		}
	}
	else{
		cout<<l/n+1<<" ";
		if((l/n+1)%2==1){
			cout<<l%n;
		}
		else{
			cout<<n+1-l%n;
		}
	}
	return 0;
} 
