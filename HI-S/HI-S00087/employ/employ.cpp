#include<bits/stdc++.h>
using namespace std;
int n,m,a[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)cin>>a[i];
    int p=0;
    for(int i=0;i<n;i++){
    	if(s[i]=='1'){
    		p=1;
    		break;
    	}
    }
    if(n==m||p==0){
    	cout<<0;
    }
    if(m==1){
    	long long sum=0,x=1;
    	for(int i=1;i<n;i++)x*=i;
    	for(int i=1;i<=n;i++){
    		int cnt=0;
    		for(int j=1;j<=n;j++)if(a[j]>=i-1)cnt++;
    		sum+=x*cnt;
    	}
    	cout<<sum;
    }
	return 0;
}
