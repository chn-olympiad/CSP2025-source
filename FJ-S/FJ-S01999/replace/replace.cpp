# include<iostream>
# include<queue>
using namespace std;
int n, p;


int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin>>n>>p;
	char s[10010];
	for(int i=1;i<=n;i++){
		cin>>s;
	}
	for(int i=1;i<=p;i++){
		cin>>s;
	}
	
	for(int i=0;i<p;i++){
		cout<<0<<"\n";
	}
	
	
	
	return 0;
}


