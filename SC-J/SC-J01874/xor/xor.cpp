#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005],b,c,d,e;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>b>>c;
	for(int i=1;i<=b;i++) cin>>a[i];
	for(int i=1;i<=b;i++){
		d=d^a[i];
		if(d==c){
			e++;
			d=0;
		}
	}
	cout<<e;
	return 0;
	fclose(stdin);
	fclose(stdout);
}