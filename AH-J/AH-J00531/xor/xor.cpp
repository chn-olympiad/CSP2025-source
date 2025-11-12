#include<bits/stdc++.h>
using namespace std;
long long a[50005],cnt=0,bj[50005],t[100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]++;
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				cnt++;
				bj[i]=1;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1]&&a[i]!=0&&bj[i]==0&&bj[i+1]==0){
				cnt++;
				i++;
			}
			
		}
		cout<<cnt;
		return 0;
	}
	if(k==1&&t[0]+t[1]==n){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
					cnt++;
					bj[i]=1;
				}
		}
		cout<<cnt;
		return 0;
	}
	cout<<"系統大哥行行好";
	return 0;
}
