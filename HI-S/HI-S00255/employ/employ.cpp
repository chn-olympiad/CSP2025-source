#include<bits/stdc++.h>
using namespace std;
const int N=1e3+6;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	long long p=0;
	queue<int> q,r;
	int x=0,k=0;
	char s[501];
	int c[N];
	cin>>n>>m;
	r.push(n);
	for(int i=0;i<n;i++) cin>>s[i];
	for(int i=0;i<n;i++){
		cin>>c[i];
		q.push(i);
	}
	for(int i=1;i<=n;i++){
		if(r.front()=1){
			for(int i=1;i<=n;i++){
				if(s[i]=='1') x++;
				if(s[i]=='0') k++;
				if(x>=m) p++;
			} 
		}
		else{
			for(int i=1;i<=n;i++){
				if(s[i]=='1') x++;
				if(s[i]=='0') k++;
				if(x>=m) p++;
			} 
		}
		if(k>c[i]) p--;
	}
	cout<<p<<endl;
	return 0;
}
