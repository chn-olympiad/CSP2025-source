//10pts
#include<bits/stdc++.h>
using namespace std;
vector<int> v, v1;
int f(int a, int b) {
//	int ans=0;
//	for(int i=a;i<=b;i++){
//		ans^=v1[i];
//	}
//	return ans;
	return v[b] ^ v[a - 1];
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	bool fl = 1;
	int n, k;
	cin >> n >> k;
	v.push_back(0);
	v1.push_back(0);
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		v.push_back(x^v[i - 1]);
		v1.push_back(x);
		if (fl == 1) {
			if (x != 1) {
				fl = 0;
			}
		}
	}
	if (fl) {
		if (k == 0) cout << n / 2;
		else if (k == 1) cout << n;
		else cout << 0;
		return 0;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int num = 0;
		int a = i;
		for (int j = i; j <= n; j++) {
			int s = f(a, j);
			if (s == k) {
				a = j + 1;
				num++;
			}
		}
		ans = max(ans, num);
	}
	cout << ans << '\n';
}
//rp++
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
int ans=0;
int a=0,n,k;
cin>>n>>k;
for(int i=0;i<n;i++){
int x;
cin>>x;
a^=x;
if(a==k){
ans++;
a=0;
}
}
cout<<ans;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
vector<int> v,v1;
int f(int a,int b){
return v[b]^v[a-1];
}
int main()
{
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
bool fl=1;
int n,k;
cin>>n>>k;
v.push_back(0);
v1.push_back(0);
for(int i=1;i<=n;i++)
{
int x;
cin>>x;
v.push_back(x^v[i-1]);
v1.push_back(x);
if(fl==1){
if(x!=1){
fl=0;
}
}
}
if(fl){
if(k==0) cout<<n/2;
else if(k==1) cout<<n;
else cout<<0;
return 0;
}
int i=1,j=1;
for(;i<=n;i++){
for(;j<=n;j++){
if(f(i,j)==k){

}
}
}
}
*/