#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(const int x,const int y){
	return x>y;
}
int main(){	
	freopen("seat.in","r",stdin);
	freopn("seat.out","w",stdout);
	int n,m,a[110];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int me=a[1],indexn=1;
	sort(a+1,a+1+n*m,cmp);	
	for(int i=1;i<=n*m;i++){
		if(a[i]==me){
			indexn=i;
			break;
		}	
	}
	int zu=(indexn-1)/n+1;
	int k=indexn-n*(zu-1);
	cout<<zu<<' ';
	if(zu%2!=0){
		cout<<k<<' ';
	}
	else{
		cout<<n+1-k<<' ';
	}	
	return 0;
}

