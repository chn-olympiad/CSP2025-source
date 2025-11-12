#include<bits/stdc++.h>
using namespace std;
struct S{
	int a,b,c;
};
int cmp(S s1,S s2){
	return s1.c<s2.c;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int a[n],b[n]={0},q=0,c[n]={0};
	S s[m];
	long long ans;
	for(int i=0;i<m;i++){
		cin>>s[i].a>>s[i].b>>s[i].c;
	}
	sort(s,s+n,cmp);
	for(int i=0;i<k;i++){
		int x;
		cin>>x;
		for(int j=0;j<n;j++){
			cin>>a[j];
		}
	}
	for(int i=0;i<m;i++){
		if(q==0){
			b[q++]=s[i].a;
			b[q++]=s[i].b;
			c[s[i].a]=1;
			c[s[i].b]=1;
		}
		else if(s[i].a==b[q]&&c[s[i].b]==0){
			ans+=s[i].c;
			b[q++]=s[i].b;
			c[s[i].b]=1;
		}
	}
	cout<<ans;
	return 0;
} 
