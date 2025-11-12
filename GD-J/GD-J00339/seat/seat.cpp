#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int a[105];
bool cmp(int s,int p){
	return s>p;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i] == x){
			int lie;
			if(i % n == 0)lie=i/n;
			else lie=i/n+1;
			if(lie % 2 == 1){
				if(i % n == 0)cout << i/n <<" "<< n;
				else cout << i/n+1 <<" "<< i%n; 
			}
			else{
				if(i % n == 0)cout << i/n <<" "<< 1;
				else cout << i/n+1 <<" "<< n-i%n+1; 
			}
			break; 
		}
	}
	
	return 0;
} 
