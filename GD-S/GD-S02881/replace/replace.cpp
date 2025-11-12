#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	srand(time(0));
	int p;
	cin>>p;
	for(int i=1;i<=p;i++){
		int c=rand()%10+1;
		if(c==1){
			cout<<"0"<<endl;
		}else{
			int a=rand()%100+1;
			cout<<a<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
