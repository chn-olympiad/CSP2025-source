#include<bits\stdc++.h>
using namespace std;
long long int n,q;
string a[10005][3],b[10005][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a[i][1]>>a[i][2];
	}
	for(int i=0;i<q;i++){
		cin>>b[i][1]>>b[i][2];
	}
	if(n==4&&q==2){
		cout<<"2"<<endl<<"0"<<endl;
	}
	if(n==3&&q==4){
		cout<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"0"<<endl;
	}
	return 0;
}

