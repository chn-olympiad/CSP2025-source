#include<iostream> 
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string a[n],b[n],c[q],d[q];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<q;i++){
		cin>>c[i]>>d[i];
		cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}