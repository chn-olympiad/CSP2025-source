//GZ-S00038 北京师范大学贵阳附属中学 冯俊豪 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,m,maxsize=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		long long l1=a.size(),l2=b.size();
		maxsize=max(maxsize,max(l1,l2));
	}
	for(int i=1;i<=m;i++){
		 string a,b;
		 cin>>a>>b;
		 if(m==1&&a.size()>maxsize){
		 	cout<<0;
		 	return 0;
		 }
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
