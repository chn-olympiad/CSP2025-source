#include<bits/stdc++.h>
using namespace std;
const int N=30;
string s;
int ar[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>ar[i];
	}int t=ar[1];
	sort(ar+1,ar+n*m+1,cmp);
	int c;
	for(int i=1;i<=n*m;i++){
		if(ar[i]==t){
			c=i;
			break;
		}
	}
	int x,y;
	x=(c%n==0?c/n:c/n+1);
	y=(x%2!=0?(c%n==0?n:c%n):n+1-(c%n==0?n:c%n));
	cout<<x<<" "<<y;
	return 0;
} 
