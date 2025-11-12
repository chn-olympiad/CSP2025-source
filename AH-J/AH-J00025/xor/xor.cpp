#include<bits/stdc++.h>
using namespace std;
long long a[10005],b[1005][1005];
struct ckx{
	long long c,d;
}y[500005];
bool cmp(ckx a,ckx b){
	return a.d<b.d;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    long long n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int x=1;
    for(int i=1;i<=n;i++){
		b[i][i]=a[i];
		if(b[i][i]==k) {
				y[x].c=i;
				y[x].d=i;
				x++;
			}
		for(int j=i+1;j<=n;j++){
			b[i][j]=b[i][j-1]^a[j];
			if(b[i][j]==k) {
				y[x].c=i;
				y[x].d=j;
				x++;
			}
		}
	}
    int r=0,ans=0;
    sort(y+1,y+x,cmp);
    for(int i=1;i<x;i++){
		if(y[i].c>r) {
			ans++;
			r=y[i].d;
		}
	}
	cout<<ans;
	return 0;
}
