#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;

int a[N];
int t[10];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]++;
	}
	if(t[1]==n){
		cout<<n/2;
	}else if(t[1]+t[0]==n){
		if(k==1){
			cout<<t[1];
		}else{
			cout<<t[1]/2+t[0];
		}
	}else{
		
	}
	
	return 0;
} 
