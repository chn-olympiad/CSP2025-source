#include<bits/stdc++.h>
using namespace std;
int n;
int a[7000];
long long sum;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1);
	for(int k=1;k<=n-3;k++){
		for(int i=3;i<=n;i++){
			do{
				int s=0;
				for(int j=k;j<=i;j++){
					s=max(a[j],s);
					s+=a[j];
				}
				if(s>s*2){
					sum++;
				}
				break;
			}while(next_permutation(a+k,a+k+i));
		}
	}
	cout<<sum%998244353<<endl;
	return 0;
}
