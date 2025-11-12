#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+7;

long long n,k,a[N],b[N],l,cnt,x;
struct str{
	int start,end; 
}c[N];
bool ss(str x,str y){
	if(x.end!=y.end)return x.end<y.end;
	else return x.start>y.start;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		b[i]=a[i];
		if(a[i]==k){
			c[l++].start=i,c[l-1].end=i;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			b[i]=b[i]^a[j];
			if(b[i]==k){
				c[l++].start=i,c[l-1].end=j;
			}
		}
	}
	sort(c,c+l,ss);
	for(int i=0;i<l;i++){
		if(c[i].start>x) x=c[i].end,cnt++;
	}
	cout << cnt;
	
	return 0;

}