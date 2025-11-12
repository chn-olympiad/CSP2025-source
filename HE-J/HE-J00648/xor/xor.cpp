#include<bits/stdc++.h>
using namespace std;
long long cnt;
const int N=5e5+5;
long long a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	long long yhh;
	long long l=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int fzc=0;
	int fzcc=1;
	while(l<=n){
	fzc=fzc^a[l];
	if(fzc==k||fzc^a[fzcc]){
	  cnt++;
	   fzcc=l+1; 
	  fzc=0;	
	  }	
	  l++;
	}
	cout<<cnt;
	return 0;
} 
