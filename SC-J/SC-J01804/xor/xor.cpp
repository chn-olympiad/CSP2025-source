#include<bits/stdc++.h>
using namespace std;
int a[500005]={};
int l[500005]={},r[500005]={};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		int num=a[i];
		for(int j=i;j<=n;j++){
			if(i==j){
				if(a[i]==k){
					cnt+=1;
					l[cnt]=i;
					r[cnt]=j;
					break;
				}
			}else{
				num=num^a[j];
				if(num==k){
					cnt++;
					l[cnt]=i;
					r[cnt]=j;
					break;
				}
			}
		}
	}
	if(cnt==1){
		cout<<cnt;
		return 0;
	}else{
		for(int i=1;i<=cnt;i++){
			for(int j=1;j<=cnt;j++){
				if(l[i]!=-1 && l[j]!=-1 && i!=j){
					if(l[i]>l[j] && r[i]<r[j]){
						l[j]=-1;
						cnt--;
					}
				}
			}
		}
		for(int i=1;i<=cnt;i++){
			for(int j=1;j<=cnt;j++){
				if(l[i]!=-1 && l[j]!=-1 && i!=j){
					if(r[i]==l[j]){
						l[j]=-1;
						cnt--;
					}else if(r[i]>l[j] && l[i]<l[j]){
						l[j]=-1;
						cnt--;
					}
				}
			}
		}
	}
	cout<<cnt;
}