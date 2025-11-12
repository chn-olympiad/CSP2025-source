#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500001];
bool A=true;
bool B=true;
int Max=0;
void dfs(int s,int st){
	if(s==n){
		if(st>Max){
			Max=st;
		}
		return;
	}
	int sum=a[s];
	for(int i=s;i<n;i++){
		if(sum==k){
			dfs(i+1,st+1);
		}
		if(i!=n-1){
			sum^=a[i+1];
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1){
			A=false;
			if(a[i]!=0){
				B=false;
			}
		}
	}
	if(A){
		cout<<n/2<<endl;
	}else if(B){
		int cnt=0;
		for(int i=0;i<n;i++){
			if(a[i]==k){
				cnt++;
			}else{
				if(i<n){
					if(a[i]^a[i+1]==k){
						cnt++;
						i++;
					}
				}
			}
		}
		cout<<cnt;
	}else{
		dfs(0,0);
		cout<<Max;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
