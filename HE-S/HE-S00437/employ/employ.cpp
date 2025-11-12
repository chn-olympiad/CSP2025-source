#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,c[510],b[510],t[510];
string a;
long long ans=1;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> a;
	for (int i=1;i<a.size();i++){
	if (a[i-1]=='0'){
	b[i+1]=b[i]+1;
	}else{
	b[i+1]=b[i]; 
	}
	}
	for (int i=1;i<=n;i++){
	cin >> c[i];
	if (b[n]<c[i]){
	cnt++;
	}
	if (b[n]==c[i]&&b[n]==0){
	cnt++;
	}
	t[c[i]]++;
	}
	for (int i=n;i>=1;i--){
	ans*=cnt;
	cnt--;
	if (b[i-1]!=b[i]&&b[i-1]==0){
	cnt+=t[0];
	cnt+=t[b[i-1]+1];
	}else if (b[i-1]!=b[i]){
	cnt+=t[b[i-1]+1];
	}
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
