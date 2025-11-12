#include<bits/stdc++.h>
using namespace std;
int a[1005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int c=a[1];
	int pm=0;
	sort(a+1,a+501,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==c){
			pm=i;
			break;
		}
	}
	int l=pm/n;
	int h=0;
	int zc=pm%n;
	if(zc==0){
		zc=n;
	}
	if(pm%n!=0){
		l++;
	}
	if(l%2==0){
		h=n-zc+1;
	}else{
		if(zc==0){
			h=n;
		}else{
			h=zc;
		}
	}
	cout<<l<<" "<<h;
	return 0;
}
