#include<bits/stdc++.h>
using namespace std;
int n,m,a[103],nm,r;
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	std::cin>>n>>m;
	nm=n*m;
	for(int i=1;i<=nm;i++) std::cin>>a[i];
	r=a[1];
	std::sort(a+1,a+nm+1,cmp);
	for(int i=1;i<=nm;i++){
		if(a[i]==r){
			int x,y;
			x=(i+n-1)/n;
			if(x%2){
				if(i%n==0) y=n;
				else y=i%n;
			} 
			else{
				if(i%n==0) y=1;
				else y=n-i%n+1;
			}
			std::cout<<x<<" "<<y;
			return 0;
		}
	}
}
