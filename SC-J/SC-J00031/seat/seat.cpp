#include<bits/stdc++.h>
#define ll long  long
using namespace std;
int n,m;
int idx;
int a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	idx=a[1];
	sort(a+1,a+1+(n*m),cmp);
	for(int i=1;i<=n*m;i++){
		if(idx==a[i]){
			idx=i;
			break;
		}
	}
//	cout<<idx<<endl;
	if(idx%n==0){
		if(idx/n%2==1){
			cout<<idx/n<<" "<<n<<endl;
		}
		else{
			cout<<idx/n<<" "<<1<<endl;
		}
	}
	else{
		if(idx/n%2==1){
			cout<<idx/n+1<<" "<<n-(idx%n)+1<<endl;
		}
		else{
			cout<<idx/n+1<<" "<<idx%n<<endl;
		}
	}
	return 0;
}

/*
3 3
94 95 96 97 98 99 100 93 92


*/
