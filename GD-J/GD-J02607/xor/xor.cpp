#include<bits/stdc++.h>
using namespace std;
int n, m, x, now=0, s[500050], t[500050], b[3100050], id=0, ans=0;
struct qwe{
	int l, r;
}a[500050];
bool cmp(qwe x, qwe y) {
	return x.r<y.r;
} 
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>>n>>m;
	memset(b, 0, sizeof(b));
	for(int i=1; i<=n; i++) {
		cin>>x;
		s[i]=s[i-1]^x;
		t[i]=s[i]^m;
	}
	t[0]=m;
	int p=(1<<21);
	for(int i=0; i<=p; i++) b[i]=-1;
	for(int i=n; i>=0; i--) {
		if(m!=0) b[t[i]]=i;
		if(b[s[i]]!=-1) {
			a[++id].l=i+1;
			a[id].r=b[s[i]];
		}
		if(m==0) b[t[i]]=i;
	}
	sort(a+1, a+id+1, cmp);
	for(int i=1; i<=id; i++) {
		//cout<<a[i].l<<" "<<a[i].r<<"\n";
		if(a[i].l>now) {
			ans++;
			now=a[i].r;
		}
	}
	cout<<ans;
	return 0;
}
