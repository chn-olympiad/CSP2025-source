#include<bits/stdc++.h>
using namespace std;

int n,m,R;
int a[200];

bool cmp(int a,int b){return a>b;}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>R;
	a[1] = R;
	for(int i = 2;i<=n*m;i++) cin>>a[i];
	sort(a+1,a+1+n*m,cmp);
	
	int weizi = 0;
	for(int i = 1;i<=n*m;i++){
		if(a[i] == R){
			weizi = i;
			break;
		}
	}
	
	int le = ceil(weizi*1.0 / n);
	cout<<le<<' ';
	
	if(le % 2 == 0){ //ÍùÉÏÅÅ 
		cout<<n-(weizi%n)+1;
	}
	else{
		if(weizi%2 == 0) cout<<n;
		else cout<<weizi%2;
	}
	return 0;
}

/*
3 3
94 95 96 97 98 99 100 93 92

*/
