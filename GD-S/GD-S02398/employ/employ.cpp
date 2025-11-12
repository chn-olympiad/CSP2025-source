#include <iostream>
using namespace std;

struct pep{
	int number;
	int pt;
};

int n,m;
long long ans=0;
string t;
bool T[510];
pep p[510];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	cin>>t;
	for(int i=1;i<=n;i++){
		T[i]=t[i]-'0';
	}
	for(int i=1;i<=n;i++){
		p[i].number=i;
		cin>>p[i].pt;
	}
	
	
	
	ans%=998244353;
	cout<<ans<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
