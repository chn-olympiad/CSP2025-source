#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int t=n*m;
	vector<int>a(t+1,0);
	for(int i=1;i<=t;i++){
		cin>>a[i];
	}
	int s=a[1];
	sort(a.begin(),a.end());
	vector<int>b(t+1,0);
	for(int i=1;i<=t;i++){
		b[i]=a[t-i+1];
	}
	int k;
	for(int i=1;i<=t;i++){
		if(b[i]==s){
			k=i;
			break;
		}
	}
	if(k%n==0){
		int w=k/n;
		cout<<w<<' ';
		if(w%2==0){
			cout<<1;
		}
		else cout<<n;
	}
	else{
		int w=k/n+1,v=k%n;
		cout<<w<<' ';
		if(w%2==1){
			cout<<v;
		}
		else cout<<n-v+1;
	}
}
