#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int stu=a[1];
	sort(a+1,a+1+n*m,cmp);
	int pos;
	for(int i=1;i<=n*m;i++){
		if(i%n==0) pos=i/n;
		else pos=i/n+1;
		if(a[i]==stu){
			cout<<pos<<" ";
			if(pos%2==1){
				if(i%n!=0) cout<<i%n;
				else cout<<n;
			}else{
				if(i%n!=0) cout<<n-(i%n)+1;
				else cout<<n;
			}
			return 0;
		}
	}
}