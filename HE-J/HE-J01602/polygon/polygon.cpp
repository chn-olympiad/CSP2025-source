#include<bits/stdc++.h>
using namespace std;
int chen(int a,int b){
	int cnt=1;
	for(int i=b+1;i<=a;i++){
		cnt*=i;
	}for(int i=1;i<=a-b;i++){
		cnt/=i;
	}
	return cnt%998244353;
}
int n,a[100005],max_chen,ans_chen;
bool flag_ch=true;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0; return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
		max_chen=max(max_chen,a[i]);
		ans_chen+=a[i];
		if(a[i]!=a[0]) flag_ch=false;
	}if(n==3){
		if(ans_chen>2*max_chen){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	if(flag_ch=true){
		int cnt=0;
		for(int i=3;i<=n;i++){
			cnt+=chen(n,i);
			cnt%=998244353;
		}
		cout<<cnt;
	}
	return 0;
}
