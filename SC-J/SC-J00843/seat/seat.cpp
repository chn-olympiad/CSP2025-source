#include<bits/stdc++.h>
using namespace std;
int a[1000];
bool cmp(int A,int B){
	return A>B;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int xiaoR=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==xiaoR){
			if(((i-1)/n+1)%2==1){
				if(i%n!=0) cout<<(i-1)/n+1<<" "<<i%n;
				else cout<<(i-1)/n+1<<" "<<n;
			}else{
				if(i%n!=0) cout<<(i-1)/n+1<<" "<<n-i%n+1;
				else cout<<(i-1)/n+1<<" 1";
			}
			break;
		}
	}
	return 0;
}