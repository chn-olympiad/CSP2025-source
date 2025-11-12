#include<bits/stdc++.h>
using namespace std;

int n,m,nm;
int a[200];
int ai;
int paim;

bool cmp(int x,int y){
	if(x>y) return true;
	return false;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	nm = n*m;
	for(int i=1;i<=nm;i++){
		cin>>a[i];
	}
	ai=a[1];
	sort(a+1,a+nm+1,cmp);
	for(int i=1;i<=nm;i++){
		if(a[i]==ai){
			paim=i;
		}
	}
	if(paim%n!=0){
		cout<<paim/n+1<<' '<<paim%n;
	}else{
		cout<<paim/n<<' '<<n;
	}
	return 0;
}
