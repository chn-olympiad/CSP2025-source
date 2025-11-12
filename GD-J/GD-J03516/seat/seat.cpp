#include<bits/stdc++.h>
using namespace std;
int paimin=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int R;
	cin>>R;
	for(int i=2;i<=n*m;i++){
		int a;
		cin>>a;
		if(a>R) paimin++;
	}
	int h=(paimin+n-1)/n;
	int l;
	if(h%2==0){
		l=5-paimin-(h-1)*n;
	}else{
		l=paimin-(h-1)*n;
	}
	cout<<h<<' '<<l;
}
