#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n*m+1,0);
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int cnt = a[1];
	sort(a.begin()+1,a.end(),greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==cnt){
			int c,r;
			if(i<=n){
				c = 1;
				r = i;
				cout<<c<<" "<<r; 
				return 0;
			}
			if(i%n==0){
				if(i/n==1){
					c = i/n;
					r = n;
				}else if(i/n==2){
					c = i/n;
					r = 1;
				}
				cout<<c<<" "<<r;
				return 0;
			}else if(i%n!=0){
				c = i/n+1;
				if(i%n==1){
					if(c%2==0){
						r=n;
					}else if(c%2==1){
						r=1;
					}
				}else{
					r = n-(i-1)/n;
				}
				cout<<c<<" "<<r;
				return 0;
			}
		}
	}
	return 0;
}
