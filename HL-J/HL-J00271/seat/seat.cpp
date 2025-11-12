#include<bits/stdc++.h>
using namespace std;

const int N=110;
int a[N];
int n,m,place;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int tatal=m*n;
	for(int i=1;i<=tatal;i++){
		cin>>a[i];
	}int score=a[1];
	sort(a+1,a+tatal+1,cmp);
	for(int i=1;i<=tatal;i++){
		if(a[i]==score){
			place=i;
			break;
		}
	}place--;
	int x=place/n+1;
	int y;
	if(x%2==1)y=place%n+1;
	else y=n-place%n;
	cout<<x<<" "<<y;

	return 0;
}
