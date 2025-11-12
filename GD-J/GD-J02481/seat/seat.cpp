#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[105];

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
	int gr=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==gr){
			int x=i/n+1,y;
			if(i%n == 0){
				x=i/n;
				if(x%2 == 0){
					y=1;
				}else{
					y=n;
				}
				
			}else{
				x=i/n+1;
				if(x%2 == 0){
					y=n-i%n+1;
				}else{
					y=i%n;
				}
			}
			cout<<x<<" "<<y;
			break;
		}
	}
	return 0;
} 
