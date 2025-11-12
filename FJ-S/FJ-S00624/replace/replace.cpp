#include<bits/stdc++.h>
using namespace std;
int n,q,m;
string a[200010],b[200010],s,ss;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin >> a[i] >> b[i];
	}
	while(q--){
		int sum=0;
		cin >> s >> ss;
		for(int i=1;i<=n;i++){
			
			if(s.find(a[i])!=-1){
			   string sss=s;
			   m=s.find(a[i]);
               sss.erase(m,a[i].size());
			   sss.insert(m,b[i]);		   
			   if(sss==ss){
			      sum++;
			   }
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
