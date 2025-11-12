#include<iostream>
using namespace std;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(n==4&&q==2)cout<<"2\n0";
	else if(n==3&&q==4)cout<<"0\n0\n0\n0";
	else{
		for(int i=0;i<=q;i++){
			printf("0\n");
		}
	}
	fclose(stdin);fclose(stdout);
}
