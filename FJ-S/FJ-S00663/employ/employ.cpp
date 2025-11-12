#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[1000],ans,sum[1000];
string s;
void fn(int k,int cnt,int mm){
	for(int i=0;i<n;++i){
		if(!(k&(1<<i))){
			if(a[cnt]<=sum[i]){
				if(cnt==n){
					return ;
//					cout<<"kkkkk";
				}
				fn(k+(1<<i),cnt+1,mm);
			}
			else {
				if(cnt==n){
//					cout<<3;
					if(mm>=m)++ans;
					return;
				}
				fn(k+(1<<i),cnt+1,mm+1);
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<n;++i){
		if(s[i-1]=='0')sum[i]=sum[i-1]+1;
		else sum[i]=sum[i-1];
	}
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
//	for(int i=0;i<n;++i)cout<<sum[i]<<" ";
	fn(0,1,0);
	cout<<ans;
	return 0;
}
