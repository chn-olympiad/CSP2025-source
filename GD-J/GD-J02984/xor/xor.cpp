#include<iostream>
#include<cstdio>
using namespace std;
int n,k,ans;
int a[500005],cnt;
bool flag=1;
int zhui[500005];
int vis1[500005],vis2[500005],cntvis;
bool check(int l,int r){
	for(int i=1;i<=cntvis;i++){
		if(r<vis1[i]) continue;
		if(l>vis2[i]) continue;
		return 0;
	}
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) cnt++;
		if(a[i]>1) flag=0;
	}
	if(flag==1){
		if(k==0) cout<<cnt/2;//RP++
		else cout<<cnt;//RP++
	}else{
		zhui[0]=0;
		zhui[1]=a[1];
		for(int i=2;i<=n;i++){
			zhui[i]=zhui[i-1]^a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n-i+1;j++){
				if(check(j,j+i-1)==0) continue;//RP++
				if((zhui[j+i-1]^zhui[j-1])==k){//RP++
					vis1[++cntvis]=j;//RP++
					vis2[cntvis]=j+i-1;//RP++
				}
			}
		}
		cout<<cntvis;//RP++
	}
	return 0;
}
