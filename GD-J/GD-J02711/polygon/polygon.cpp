#include<iostream>
using namespace std;

int n;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		int a,b,c;
		cin>>a>>b>>c;
		if(a+b+c>2*(max(a,max(b,c)))) cout<<1;
		else cout<<0;
	}else{
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		int MAXN=0;
		for(int i=0;i<n;i++){
			if(a[i]>MAXN) MAXN=a[i];
		}
		if(MAXN==1) cout<<0;
	}
	return 0;
}
