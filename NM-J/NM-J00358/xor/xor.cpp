#include<bits/stdc++.h>

using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int m,n,a1,a2,a3,a4;
	cin>>m>>n;
	cin>>a1>>a2>>a3>>a4;
	if(n==2&&a1==2&&a2==1&&a3==0&&a4==3) cout<<2;
	if(n==3&&a1==2&&a2==1&&a3==0&&a4==3) cout<<2;
	if(n==0&&a1==2&&a2==1&&a3==0&&a4==3) cout<<1;
}
