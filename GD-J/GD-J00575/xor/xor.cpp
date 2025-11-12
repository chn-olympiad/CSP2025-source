#include<bits/stdc++.h>
#define fo(i,x,y) for(int i=(x);i<=(y);i++)
using namespace std;
bool b[1048586]={1};
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,m,s=0,t=0;
	cin>>n>>m;
	fo(i,1,n){
		cin>>a[i];
		a[i]^=a[i-1];
	}
	fo(i,1,n)
		if(b[a[i]^a[t]^m]){
			s++;
			fo(j,t+1,i-1)
				b[a[j]^a[t]]=0;
			t=i;
			b[0]=1;
		}
		else
			b[a[i]^a[t]]=1;
	cout<<s;
	return 0;
}
