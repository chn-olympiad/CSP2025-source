#include<bits/stdc++.h>
using namespace std;
const int lb=200010;
int n,q,k; string s1[lb],s2[lb],t1,t2,a,b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d\n",&n,&q);
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	while(q--){
		cin>>t1>>t2;
		k=0;
		for(int i=1;i<=n;i++){
			a=t1,b=t2;
			while(a.find(s1[i])!=EOF&&a!=b){
				int f=a.find(s1[i]);
				for(int j=0;s2[i][j];j++)
				  a[f+j]=s2[i][j];
			}
			if(a==b) k++;
		}
		printf("%d\n",k>1?k:0);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
