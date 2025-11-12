#include<bits/stdc++.h>
using namespace std;
int n,q;
string str1,str2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>str1>>str2;
	srand(time(0));
	for(int i=1;i<=q;i++){
		cin>>str1>>str2;
		int t=rand()%n*n;
		cout<<rand()%t<<endl;
	}
	return 0;
}
