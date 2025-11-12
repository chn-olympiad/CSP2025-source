#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+10;
string s;
int tmp=0,a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,tmp=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==k){
			tmp++;
		} 
	}
	if(k==0){
		cout<<1;
		return 0;
	}
	cout<<tmp+1;
	return 0;
} 