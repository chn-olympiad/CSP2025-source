#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int zheng(int a,int b){
	int n=a/b;
	if(a%b==0){
		return n;
	}
	else{
		return n+1;
	}
}
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int k=n*m;
	int b;
	for(int i=1;i<=k;i++){
		
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+k+1,cmp);
	int cnt;
	for(int i=1;i<=k;i++){
		if(a[i]==b){
			cnt=i;
			break;
		}
	}
	int x=zheng(cnt,n);
	int c=cnt%n;
	int y;
	if(x%2==0){
		
		if((n-c+1)%n==0){
			y=n-c+1;
		}
		else{
			y=(n-c+1)%2;
		}
	}
	else{
		y=c;
	}
	cout<<x<<" "<<y;
    return 0;
}
