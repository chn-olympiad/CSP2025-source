#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
const int N=5e5+10;
int n,k;
int a[N];
bool st[N];
vector<int> ip;

int xr(int l,int r){
	int x=a[l];
	for(int i=l+1;i<=r;i++)x^=a[i];
	return x;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	int res=0;
	for(int i=1;i<=n;){
		for(int j=i;j<=n;j++){
			if(xr(i,j)==k&&!st[j]){
				res++;
				if(j==n){
					cout<<res;
					return 0;
				}
				ip.push_back(i),i=j+1;
			}
			if(xr(i,j)!=k&&j==n){
				st[j]=1;
				if(ip.empty()){
					cout<<0;
					return 0;
				}
				i=ip.back();
				ip.pop_back();
				res--;
			}
		}
	}
	cout<<res;
	return 0;
}
