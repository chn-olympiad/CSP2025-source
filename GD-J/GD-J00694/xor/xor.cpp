#include<iostream> 
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#define ll long long
using namespace std;
int a[500005];
int h[500005];
int n,k;
int ans=-1;
int anslst;
void dfs(int cnt,int i){
	if(i>=anslst&&cnt<ans)return ;
	if(cnt>ans){
		ans=cnt;
		anslst=i;
	}
	if(i>n)return ;
	if(a[i]==k)dfs(cnt+1,i+1);//,cout<<i<<" "<<cnt<<" ";
	for(int j=i+1;j<=n;j++){
		if(a[j]==k)dfs(cnt+1,j+1);
		int tm=h[j];
		tm^=h[i-1];
		if(tm==k){
			dfs(cnt+1,j+1);//,cout<<i<<" x "<<j<<" "<<cnt<<" ";
			break;
		}
		//if(i==1&&j==4)cout<<tm<<"a ";
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	h[0]=0;
	cin>>n>>k;
	bool flag=1;
	int as=0;
	int ls=0;
	bool b=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0&&a[i]!=1)flag=0;
		if(a[i]==1){
			as++;
			if(b){
				if(a[i-1]==1)b=0,ls++;
				else b=0;
			}
			else b=1;
			
		}
		h[i]=h[i-1]^a[i];
	}
	if(flag){
		if(k==0)cout<<n-as+ls;
		else cout<<as;
	}
	else{
		dfs(0,1);
		cout<<ans;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

