#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
long long n,k,a[N+1],s[N+1],cnt=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>k;
	s[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
//		cout<<s[i]<<' ';
	}
//	cout<<endl;
	int index=1;
	for(int j=1;j<=n;j++){
		for(int i=j;i>=index;i--){
			long long num=s[j]^s[i-1];
//			cout<<i<<' '<<j<<' '<<num<<endl;
			if(num==k){
				cnt++;
				index=j+1;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
} 
