#include<bits/stdc++.h>
using namespace std;
int a[110];
int a1;
int n,m;
bool cmp(int a,int b){
	return a>b; 
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a1=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			if(a[i]%n!=0){
				cout<<a[i]/n+1<<' ';
				if((a[i]/n+1)%2==0)cout<<n-(a[i]%n)+1;
				else cout<<a[i]%n;
			}
			else{
				cout<<a[i]/n<<' ';
			    if((a[i]/n)%2==0)cout<<1;
			    else cout<<n;
			}
			return 0;
		} 
	} 
	return 0;
}
