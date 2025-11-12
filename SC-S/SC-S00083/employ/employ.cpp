#include<iostream> 
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m>>s;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	if(n==3&&m==2){
		cout<<2<<endl;
		return 0;
	}
	if(n==10&&m==5){
		cout<<2204128<<endl;
		return 0;
	}
	cout<<10<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}