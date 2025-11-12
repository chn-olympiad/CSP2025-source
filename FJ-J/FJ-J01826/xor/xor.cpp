#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
long long a[N],p[N],s[304][305];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[i]==a[j]){
				s[i][j]=a[i];
				p[a[i]]=max(p[a[i]],(long long)j-i);
			}
			else{
				p[s[i][j]]=max(p[s[i][j-1]],(long long)j-i);
			}
		}
	}
	cout<<p[k]<<endl;
	return 0;
} 
