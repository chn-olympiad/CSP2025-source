#include <bits/stdc++.h>
using namespace std;
int n,k,a[100000000],l,r,ans,cnt=0,t;
int q(){
	ans = a[l];
	l++;
	while(l<=r){
		ans ^= a[l];
		l++;
		t = ans;
		if(l==0 && ans==k){
			cnt++;
			ans = a[l];
		}
		if(ans==k&&t^a[l]!=k){
			cnt++;
			ans = a[l];
		}
	}
}
int q3(int x,int y){
	ans = a[x];
	x++;
	while(x<=y){
		ans ^= a[x];
		x++;
		t = ans;
		if(x==0 && ans==k){
			cnt++;
			ans = a[x];
		}
		if(ans==k&&t^a[x]!=k){
			cnt++;
			ans = a[x];
		}
	}
}
int q1(int p){
	int j=p+1;
	ans = a[j];
	for(int i=p+1;i<r;i++){
		ans ^= a[i+1];
	}
	if(ans!=k) q3(j,r);
	else{
		cnt++;
	}
}
int q2(int o){
	int j=o;
	int h=r-1;
	ans = a[o];
	for(int i=o;i<r-1;i++){
		ans ^= a[i+1];
	}
	if(ans!=k) q3(j,h);
	else{
		cnt++;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	l = 1;
	r = n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0) t=i;
	}
	if(a[l]==k && a[r]==k){
		cnt = cnt + 2;
		q3(l+1,r-1);
	}
	else{
		if(a[l] == k){
			cnt++;
			q1(l);
		}
		if(a[r] == k){
			cnt++;
			q2(r);
		}
		else{
			q();
		}
	}
	if(k==0){
		cout << 1 << endl;
	}
	else{
		cout << cnt << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}