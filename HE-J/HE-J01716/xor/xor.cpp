#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+50;
int n,k;
int a[N],sj=0,maxn=INT_MIN;
bool flag[N]={0};
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0&&!flag[i]){sj++;flag[i]=1;}
			if(a[i]==a[i-1]&&a[i]!=0&&!flag[i]&&!flag[i-1]){
				sj++;
				flag[i]=flag[i-1]=1;
			}
			if(a[i]==a[i+1]&&a[i]!=0&&!flag[i]&&!flag[i+1]){
				sj++;
				flag[i]=flag[i+1]=1;
			}
		}
	}
	else if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1&&!flag[i]){sj++;flag[i]=1;}
			if(a[i]==a[i-1]&&a[i-1]==a[i-2]&&a[i]!=1&&!flag[i]&&!flag[i-1]&&!flag[i-2]){
				sj++;
				flag[i]=flag[i-1]=flag[i-2]=1;
			}
			if(a[i]==a[i+1]&&a[i+2]==a[i+1]&&a[i]!=1&&!flag[i]&&!flag[i+1]&&!flag[i+2]){
				sj++;
				flag[i]=flag[i+1]=flag[i+2]=1;
			}
			if(a[i]==a[i-1]&&a[i-1]==a[i+1]&&a[i]!=1&&!flag[i]&&!flag[i+1]&&!flag[i-1]){
				sj++;
				flag[i]=flag[i+1]=flag[i-1]=1;
			}
		}
	}
	cout<<sj;
	return 0;
}
