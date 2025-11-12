#include<bits/stdc++.h>
using namespace std;
int n,m,w=998244353;
int s[510];
int a[510];
int ans;
int jc1(int x){
	if(x==0) return 1;
	int g=1;
	for(int i=1;i<x;i++){
		g*=2;
	}
	return g;
}
void jc(int x){
	int t=0;
	for(int i=1;i<=x;i++){
		if(a[i]=a[i+1]){
			t++;
		}else{
			ans=ans*jc1(t)%w;
			t=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    int x;
   	cin>>x;
   	int k=0;
   	for(int i=1;i<=n;i++){
   		if(x!=0){
   			s[i]=x%10;
   			x/=10;
		   }
		if(s[i]==1) k++;
	   }
    for(int i=1;i<=n;i++) cin>>a[i];
        if(k<m){
	   	cout<<0<<endl;
	   	return 0;
	}
	sort(a+1,a+1+n);
	int t=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i]==1&&t<=a[i]){
			cnt++;
		}else{
			t++;
		}
		if(cnt>=m){
			ans++;
			jc(n);
			break;
		}
	}
	cout<<ans%w<<endl;
    //for(int i=1;i<=n;i++) cout<<s[i];
	return 0;
}
