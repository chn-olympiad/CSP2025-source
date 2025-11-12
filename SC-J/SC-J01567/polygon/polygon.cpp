#include<bits/stdc++.h> 
using namespace std;
int a[10];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	if(n<3)cout<<0;
	else if(n==3){
		int maxn=0;
		int h=0;
		for(int i=1;i<=3;i++){
			cin>>a[i];
			if(maxn<a[i])maxn=a[i];
			h+=a[i];
		}
		if(2*maxn<h)cout<<1;
		else cout<<0;
	}
	return 0;
}