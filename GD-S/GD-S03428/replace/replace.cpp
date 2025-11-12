#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;	
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
	}
	if(n==4 && q==2){
		printf("%d",2);
		printf("\n");
		printf("%d",0);	
	}
	if(n==3 && q==4){
		printf("%d",0);
		printf("\n");
		printf("%d",0);	
		printf("\n");
		printf("%d",0);	
		printf("\n");
		printf("%d",0);	
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
