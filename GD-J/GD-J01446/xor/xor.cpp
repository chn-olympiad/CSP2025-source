#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,k;
int a[N];
int answer=0;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
	}
	int i=1,j=1;
	for(i=0;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if((a[i]^a[j])==k){
				i=j-1;
				answer++;
				break;
			}
		}
	}
	cout<<answer;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
