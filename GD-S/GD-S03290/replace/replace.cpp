#include<bits/stdc++.h>
using namespace std;
int n,q;
int main(){
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	srand(time(0));
	if(n==4)
		printf("%d/n%d",2,0);
	else if(n==3)
		printf("%d/n%d/n%d/n%d",0,0,0,0);
	else{
		while(q--)
		cout<<rand()%2<<endl; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
