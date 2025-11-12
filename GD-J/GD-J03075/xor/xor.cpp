#include<bits/stdc++.h>

using namespace std;

int const maxx=6e5+10;

int n,k,ans=0;
int a[maxx],s[maxx];

int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=cnt;j<i;j++){
			int ay=s[i]^s[j];
			if(ay==k){
				cnt=i;
				ans++;
				break;
			}
		}
	}
	
	cout<<ans;
	
	return 0;
}

