#include<bits/stdc++.h>
using namespace std;
int n,ans,q;
string a[200005],b[200005];
int pos(string x,string t1,string y,string t2){
	int lx=x.size(),ly=t1.size();
	for(int i=0;i<=ly-lx;i++){
		int f=1;
		for(int j=i;j<=i+lx-1;j++){
			if(t1[j]!=x[j-i]){
				f=0;
				break;
			}
		}
		if(f){
			string t=t1;
			int la=x.size();
			for(int j=0;j<t1.size();j++){
				if(!(j<i||j>=(i+la))) t[j]=y[j-i];
			}
			if(t==t2) ans++;
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	if(n<=200&&q<=200){
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i];
		}
		while(q--){
			string t1,t2;
			cin>>t1>>t2;
			ans=0;
			for(int i=1;i<=n;i++){
				pos(a[i],t1,b[i],t2);
			}
			printf("%d\n",ans);
		}
	}else{
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i];
		}
		while(q--){
			string t1,t2;
			cin>>t1>>t2;
			printf("0\n");
		}
	}
	return 0;
} 
