#include<bits/stdc++.h> 
using namespace std;

const int N = 1e6+5;
long long i,j,n,m,k,l[N],x,y,a[N],s[N],b[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n>> k;
	for(i = 1;i <= n;i ++){
		cin >> a[i];
		l[i] = 0;
		s[i] = s[i-1]^a[i];
	}
	for(i = 0;i <= n;i ++){
		for(x = i+1;x <= n;x ++){
			int y = s[x]^s[i];
			if(y == k){
				break;
			}
		}
		if(x == n+1)continue;
		l[x] = max(l[x],i+1);
		b[x] = 1;
		
	}
	int r = 0,cnt = 0;
	for(i = 1;i <= n;i ++){
		if(b[i] == 1){
			if(r >= l[i])continue;
			else{
				cnt ++;
				r = i;
			}
		}
	}
	cout << cnt;
	return 0;
}