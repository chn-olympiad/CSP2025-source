#include<bits/stdc++.h>
using namespace std;
const int N=5001;
int n;

//ÓÒÎªi ×î¼Ñ ×óÎªans[i]£» 
int ans[N];

long long a[N];
long long k,a_i;
int cnt[N];

int x;
int inn;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	memset(ans,-1,sizeof(ans));
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a_i;
		for(int l=1;l<=i;l++){
			a[l]=a[l]^a_i;
			if(a[l]==k){
				ans[i]=l;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(ans[i]!=-1){
			cnt[i]=max(cnt[i-1],cnt[ans[i]-1]+1);
		}
		else{
			cnt[i]=cnt[i-1];
		}
	}
	cout<<cnt[n];
	
	fclose(stdin);
	fclose(stdout);
	return 11;
}
