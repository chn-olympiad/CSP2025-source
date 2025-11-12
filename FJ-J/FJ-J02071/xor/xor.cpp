#include<bits/stdc++.h> 
using namespace std;
const int N=5e5+5;
int n,k;
long long a[N],ans,cnt;
bool q;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(!a[i]) {
			q=1;
			cnt++;
		}
		else ans++;
	}
	if(k==0&&!q){
		cout<<0;
		return 0;
	}
	if(k==1){
		cout<<ans;
		return 0;
	}
	cout<<cnt;
	return 0;
}
