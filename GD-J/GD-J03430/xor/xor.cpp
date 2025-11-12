#include <bits/stdc++.h>
using namespace std;
int a[500010],flag[500010]={};
int d(int l,int r){
	if(a[l]==0||a[r]==0) return -1;
	if(l==r) return a[l];
	if(l=r-1) return (a[l]^a[r]);
	return d(l,r-1)+d(r,r);
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int tx[500010],count=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
			if(d(i,i)==k){
				count++;
				flag[i]=1;
			}
	 	else if(d(i,i+1)==k&&flag[i]){
				flag[i]=1;
				flag[i+1]=1;
				count++;
			}
			else if(d(i,i+2)==k&&flag[i]&&flag[i+1]){
				flag[i]=1;
				flag[i+1]=1;
				flag[i+2]=1;
				count++;
			}
			else if(d(i,i+3)==k&&flag[i]&&flag[i+1]&&flag[i+2]){
				flag[i]=1;
				flag[i+1]=1;
				flag[i+2]=1;
				flag[i+3]=1;
				count++;
			}
				else if(d(i,i+4)==k&&flag[i]&&flag[i+1]&&flag[i+2]&&flag[i+3]){
				flag[i]=1;
				flag[i+1]=1;
				flag[i+2]=1;
				flag[i+3]=1;
				flag[i+4]=1;
				count++;
			}
				else if(d(i,i+5)==k&&flag[i]&&flag[i+1]&&flag[i+2]&&flag[i+3]&&flag[i+4]){
				flag[i]=1;
				flag[i+1]=1;
				flag[i+2]=1;
				flag[i+3]=1;
				flag[i+4]=1;
				flag[i+5]=1;
				count++;
			}
		}
		cout<<count+1;
		fclose(stdin);
		fclose(stdout);	
	return 0;	
	}


