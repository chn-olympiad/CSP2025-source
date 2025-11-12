#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,k,a[N],s[N],f[N];
vector<int> ys[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
//	cout<<k<<endl;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=(s[i-1]^a[i]);
//		cout<<s[i]<<" ";
	}
//	cout<<endl;
//	for(int i=1;i<=n;i++){
////		cout<<i<<"---\n";
//		for(int j=1;j<=i;j++){
////			cout<<j<<" ";
//			if((s[i]^s[j-1])==k){
//				ys[i].push_back(j);
////				cout<<(s[i]^s[j-1]);
//			}
////			cout<<endl;
//		}
//	}
//	cout<<endl;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		for(int j=i-1;j>=0;j--){
//			cout<<i<<" "<<j<<" "<<(s[i]^s[j])<<endl;
			if((s[i]^s[j])==k){
				f[i]=max(f[i],f[j]+1);
				break;
			}
		}
//		cout<<f[i]<<endl;
	}
	cout<<f[n];
}

