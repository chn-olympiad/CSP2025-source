#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	return x>y;
}
int a[105];
//int sea[105][105];
int main(){
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ansl,ansh,fzc;
	cin>>n>>m;
	int cnt=n*m;
	for(int i=1;i<=cnt;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		if(a[i]==r){
			fzc=i;
			break;
		}
	}
	ansl=fzc/n;
	if(fzc%n!=0)ansl++;
    if(ansl%2==0){
    	fzc=fzc-(n*(ansl-1));
    	ansh=n-fzc+1;
	}
	else {
		fzc=fzc-(n*(ansl-1));
		ansh=fzc;
	}
	cout<<ansl<<" "<<ansh;
	return 0;
}
