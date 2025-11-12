#include <iostream>
using namespace std;
const int MAXN=5000050;

struct str{
	char s1;
	char s2;
};
struct quest{
	char q1;
	char q2;
};
str S[MAXN];
quest Q[MAXN];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>S[i].s1>>S[i].s2;
	}
	for(int i=1;i<=q;i++){
		cin>>Q[i].q1>>Q[i].q2;
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
