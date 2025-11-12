#include<bits/stdc++.h>
using namespace std;
const int MAXN=2*pow(10,4);
int n,k,ans=0;
int arr[MAXN];
bool visit[MAXN];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(visit,1,sizeof(visit));
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
		for(int l=0;l<n;l++){
			for(int r=l;r<n;r++){
				if(visit[l]!=0&&visit[r]!=0){
					int num=arr[l];
					for(int i=l+1;i<=r;i++){
						num=num xor arr[i];
					}
					if(num==k){
						for(int i=l;i<=r;i++){
							visit[i]=0;
						}
						ans++;
					}
				}
			}
		}	
	cout<<ans;
	return 0;
}
