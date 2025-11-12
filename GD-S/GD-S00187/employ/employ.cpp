#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],h[505],v[505];
long long d=0;
string s;
void xx(int x){
	if(x==n){
		queue<int> q;
		for(int i=0;i<n;i++){
			q.push(a[i]);
		}
		int b=0,c=0;
		for(int i=0;i<n;i++){
			while(!q.empty()&&c>=q.front()){
				q.pop();
			}
			if(q.empty()){
				break;
			}
			if(s[i]=='1'){
				b++;
			}else{
				c++;
			}
			q.pop();
		}
		if(b>=m){
			d++;
			d%=998244353;
		}
	}
	for(int i=0;i<n;i++){
		if(v[i]==0){
			v[i]=1;
			h[x]=a[i];
			xx(x+1);
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	xx(0);
	cout<<d;
	return 0;
} 
