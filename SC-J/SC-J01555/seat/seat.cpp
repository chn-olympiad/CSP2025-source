#include<bits/stdc++.h>
using namespace std;

int n,m,a[101],rg,id;
bool comp(int a,int b){
	return a>b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>a[i];
	}
	rg=a[1];
	sort(a+1,a+n*m+1,comp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==rg){
			id=i;
			break;
		}
	}
	int r=(id+n-1)/n;
	int c;
	id-=n*(r-1);
	if(r&1==1){
		c=id;
	}else{
		c=n-id+1;
	}
	cout<<r<<" "<<c<<endl;
    return 0;
}
