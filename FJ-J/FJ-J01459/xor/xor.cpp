#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500005],f[1005][1005],pos,ans;
struct T{
	int a,b;
}t[1000005];
bool cmp(T x,T y){
	return x.b<y.b;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		f[i][i]=a[i];
		if (f[i][i]==k){
			t[++pos].a=i;
			t[pos].b=i;
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			f[i][j]=(f[i][j-1]^a[j]);
			if (f[i][j]==k){
				t[++pos].a=i;
				t[pos].b=j;
			}
		}
	}
	sort(t+1,t+pos+1,cmp);
	int last=0;
	for (int i=1;i<=pos;i++){
		if (t[i].a>t[last].b){
			last=i;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
