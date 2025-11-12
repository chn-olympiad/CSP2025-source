#include<iostream>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,c=0;
	char a[20010],b[20010],e,d;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<q;i++){
		cin>>e>>d;
		for(int j=0;j<n;j++){
			if(e==a[j])c++;
			if(d==b[j])c++;
		}
		cout<<c<<endl;	
	}
	return 0;
}
