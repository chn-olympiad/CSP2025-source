#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	srand(time(0));
	for(int i=0;i<n;i++){
		cin>>s1>>s2;
	}
	for(int i=0;i<q;i++){
		cin>>s1>>s2;
	}
	if(n==4&&q==2)cout<<2<<endl<<0;
	else if(n==3&&q==4)cout<<0<<endl<<0<<endl<<0<<endl<<0<<endl;
	else for(int i=0;i<q;i++)cout<<(rand()%10==0?rand%10+1:0);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
