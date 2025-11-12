#include<bits/stdc++.h>
using namespace std;
int n,m,k,p;
int a[1005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+1+(n*m),cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			p=i-1;
			break;
		}
	}
	int kn,km;
	kn=(p/n)+1;
	if(kn%2==0)
		km=n-(p%n);
	else
		km=(p%n)+1;
	cout<<kn<<" "<<km;
	return 0;
}
//2  1  2
