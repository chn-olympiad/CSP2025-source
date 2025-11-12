#include<bits/stdc++.h>
using namespace std;
int f[1000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int k=n*m;
    for(int i=1;i<=k;i++){
    	cin>>f[i];
	}
	int o=f[1],b;
	sort(f+1,f+1+k,cmp);
	for(int i=1;i<=k;i++){
        if(f[i]==o){
        	b=i;
        	break;
		}
	}
	int c=ceil(1.0*b/n),r=b%n;
	if(c%2==1){
		if(r==0){r=n;}
	cout<<c<<" "<<r;
		
	}else{
		if(r==0){r=n;}
	cout<<c<<" "<<n-r+1;
	}
	return 0;
}
