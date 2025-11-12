#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=110; 

ll a[N],sum,w;
ll n,k;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++){
	w++;
	cin>>a[i];
}
	if(k==0){
		cout<<w/2;
	}
	if(k==1){
		int q;
		for(int i=0;i<=n;){
			if(a[i]==1&&a[i+1]==0){
				q++;
				i+=2;
				continue;}
			if(a[i]==0&&a[i+1]==1){
				q++;
				i+=2;
				continue;}
		if(a[i]==1&&a[i+1]==1&&a[i+2]==1){
				q++;
				i+=3;
				continue;}
		}
		cout<<q;
	}
} 