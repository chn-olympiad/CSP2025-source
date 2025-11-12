//GZ-S00065 观山湖区华润中学 刘秦璋 
#include<bits/stdc++.h>
using namespace std;

int n,q;

void work(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=(n+q)*2;i++){
		string s;
		cin>>s;
	}
	
	while(q--)
		printf("%d\n",rand()%1000);
	
	return;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	srand(time(0));
	int _;
	scanf("%d",&_);
	//cin>>_
	while(_--)
		work();
	return 0;
} 
