#include<bits/stdc++.h>
using namespace std;
int a[110]; 
int b[15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	int sum = n*m;
	for(int i = 1;i<=sum;i++){
		cin>>a[i];
	}
	int ai = a[1];
	sort(a+1,a+sum+1,greater<int>());
	for(int i = 1;i<=sum;i++){
		if(a[i]==ai){
			ai = i;
			break;
		}
	}
	int brr = n;
	for(int i = 1;i<=n;i++){
		b[i] = brr;
		brr-=1;
	}
	int ma = (ai-1)/n+1,na = (ai-1)%n+1;
	if(ma%2==0){
		na = b[na];
	}
	cout<<ma<<" "<<na;
	return 0;
}
