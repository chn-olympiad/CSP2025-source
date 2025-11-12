#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,R;
	cin>>n>>m;
	int s=n*m;
	int a[s];
	for(int i=1;i<=s;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+1+s,cmp);
	for(int i=1;i<=s;i++){
		if(R==a[i]){
			int n1=(i-1)/n+1;
			if(n1%2==0){
				cout<<n1<<" "<<m-i%n+1;
				return 0;
			}else{
				cout<<n1<<" "<<(i-1)%n+1;
				return 0;
			}
		}
	}
	return 0;
}
