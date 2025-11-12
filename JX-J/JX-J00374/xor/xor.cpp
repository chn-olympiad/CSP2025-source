#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,k;
int a[500010];
bool b;
int x,y;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			y++;
			b=true;
		}
		else{
			x++;
		}
	}
	if(b==false){
		cout<<n/2;
	}
	else{
		if(k==0){
			cout<<y+x/2;
		}
		else{
			cout<<x;
		}
	}
	return 0;
}
