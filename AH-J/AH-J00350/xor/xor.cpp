#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],b[500010],cs;
struct node{
	long long st,e,h,c;
}s[500010];
bool cmp(node x,node y){
	return x.c<y.c;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			s[i].h=a[i];
			for(int j=i;j<=n;j++){
				s[i].c=j-i;
				s[i].st=i;
				s[i].e=j;
				for(int d=i+1;d<=j;d++){
					s[i].h^=a[d];
				}
			}
		}
		cout<<n/2;
		return 0;
	}
	if(k==1){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			s[i].h=a[i];
			for(int j=i;j<=n;j++){
				s[i].c=j-i;
				s[i].st=i;
				s[i].e=j;
				for(int d=i+1;d<=j;d++){
					s[i].h^=a[d];
				}
			}
		}
		sort(s+1,s+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(s[i].h==k){
				for(int j=s[i].st;j<=s[i].e;j++){
					if(b[i]==0){
						b[j]=1;
					}
					else{
						break;
					} 
					if(j==s[i].e){
						cs++;
					}
				}
			}	
		}
		cout<<cs;
	}
}
