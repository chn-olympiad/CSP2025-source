#include<bits/stdc++.h>
#define ll long long
#define y1 y114514
using namespace std;
const int N=5e5+10;
int n,k;
int a[N];
bool s1[N];
bool s2[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			sum++;
			s1[i]=1;
			s2[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			bool f=true;
			for(int y=i;y<=j;y++){
				if(s1[y]==1||s2[y]==1)f=false;
			}	
			if(!f)continue;
			ll ans=0;
			for(int t=i;t<=j;t++){
				ans^=a[t];
			}
			if(ans==k){
				sum++;
				
			}
		}
	}
	cout<<sum;
	return 0;
}
/*
I AK CSP-J! 
*/
