#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[200005];
string s[200005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    bool l = true,ll = true;
    int u=0,v=0;
    for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i] != a[i-1] && i != 1){
			l = false;
		}
		if(a[i] != 1 && a[i] != 0){
			ll = false;
		}
		if(a[i] == 1){
			u++;
		}
		if(a[i] == 1){
			v++;
		}
	}
	if(l == true && k == 0){
		cout<<n/2;
		return 0;
	}
	if(ll == true && (k == 0 || k == 1)){
		if(k == 0){
			cout<<min(u,v);
			return 0;
		}
		else{
			cout<<u/2+v/2;
		}
	}
    return 0;
}
