#include<iostream>
#include<algorithm>
using namespace std;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x;
	cin>>x;
	a[1]=x;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int fi;
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			fi=i;
			break;
		}
	}
	int c=(fi-1)/n+1;
	fi-=(c-1)*n;
	int r=(c%2==0 ? n-fi+1:fi);
	cout<<c<<" "<<r;
	return 0;
}
