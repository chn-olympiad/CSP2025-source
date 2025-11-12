#include<bits/stdc++.h>
using namespace std;

int n,m;
int h,l;
int a[105];

int cmp(int a,int b){
	return a>b;
}
void output(){
	cout<<l<<" "<<h<<endl;
}
int main(){
 	freopen("seat.in","r",stdin);
 	freopen("seat.out","w",stdout);
 	cin>>n>>m;
 	int c=n*m;
	for(int i=1;i<=c;i++){
		cin>>a[i];
	}
	int tmp=a[1],place;
	sort(a+1,a+c+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==tmp) {
			place=i;
			break;
		}
	}
	if(place%n==0) {
		l=(place/n);
		if(l%2==0) h=1;
		else h=n;
		output();
		return 0;
	}
	else {
		l=place/n+1;
		tmp=place-n*(l-1);
		if(l%2==0){
			h=n-tmp+1;
			output();
			return 0;
		}
		else {
			h=tmp;
			output();
			return 0;
		}
	}
 	return 0;
 }
