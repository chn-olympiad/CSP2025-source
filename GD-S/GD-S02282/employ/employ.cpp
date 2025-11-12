#include<bits/stdc++.h>
using namespace std;
long long n,m,x,ans=1,p,v,q;
string s;
struct node{
	long long c;
}a[555];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i].c;
		
	}
	int len=s.size();
	for(int i=0;i<=len-1;i++){
		if(s[i]==1) x++;
	}
	if(x==0){
		cout<<0;
		return 0;
	}
	if(m==n&&x!=n){
		cout<<0;
		return 0;
	}else{
		for(int i=0;i<=n-1;i++){
			ans+=ans*(n-i);
		}
		cout<<ans;
		return 0;
	}
//	x=0;
//	ans=1;
//	for(int i=0;i<=len-1;i++){
//		if(s[i]==1){
//			for(int j=1;j<=n;j++){
//				if(a[j].c>x){
//					for(int k=j+1;k<=n;k++){
//						if(a[k].c==a[j].c) p++;
//						if(a[k-v-1].c<a[j].c&&a[k-v-1].c>a[q]) p++;
//						v=k;
//					}
//					q=j;
//					break;
//				}
//			}
//			ans+=p;
//		}else x++;
//	}
//	cout<<ans;
	return 0;
} 
