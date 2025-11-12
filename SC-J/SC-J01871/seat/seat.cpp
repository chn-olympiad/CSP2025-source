#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=1e4+10;
int n,m;
int a[N];
int now;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==x){
			now=n*m-i+1;
		}
	}
	int w,h;
	w=now/n+1;
	h=now%n;
	if(h==0){
		w--;
		h=n;
	}
	if(w&1){
		cout<<w<<' '<<h;
	}else{
		cout<<w<<' '<<n-h+1; 
	}
	return 0;
}

//QAQ 100pts 