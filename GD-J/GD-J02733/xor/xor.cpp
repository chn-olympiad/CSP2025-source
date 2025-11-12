#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+7;
int a[maxn],n,k;
bool vis[maxn];
bool obj_a=true,obj_b=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) obj_a=false;
		else if(a[i]>1) obj_b=false;
	}
	if(k==0&&obj_a==true){
		cout<<n/2;
	} 
	else if(obj_b=true){
		if(k==1){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					vis[i]=1;
					cnt++;
				}
			}
			cout<<cnt;
		}
		else if(k==0){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					vis[i]=1;
					cnt++;
				}
				else if(a[i-1]==1&&a[i]==1&&vis[i-1]==0){
					vis[i-1]=1,vis[i]=1;
					cnt++;
				}
			}
			cout<<cnt;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
