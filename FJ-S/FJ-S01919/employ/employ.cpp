#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int g,num;
	char s;
}a[505];
int cmp(node c,node d){
	return c.num<d.num;
}
char s[505];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,sum=998244353,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].g;
		a[i].num=i;
	}
	do{
		int cnt=0,k=0;
		for(int i=1;i<=n;i++){
			if(a[i].g-k>0){
				if(s[i]=='1') cnt++;
		        else if(s[i]=='0') k++;
			}
			if(cnt>=m){
				ans=(ans+1)%sum;
				break;
			} 
	    }
	    
	}while(next_permutation(a+1,a+1+n,cmp));
	cout<<ans;
	return 0;
}