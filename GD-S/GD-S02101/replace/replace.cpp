#include <iostream>
#include <unordered_map>
using namespace std;

const int MAXN=5e6+5;

int n,q,st,ed;

long long ans;

string A,B;

unordered_map <string,unordered_map<string,bool> > has;

void init(){
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++){
		cin>>A>>B;
		has[A][B]=1;
	}
	return;
}

void solve(){
	cin>>A>>B;
	if (A.length()!=B.length()){
		printf("%d\n",0);
		return;
	}
	n=B.length();
	st=1;
	ed=n;
	for (int i=1;i<=n;i++){
		if (A[i-1]!=B[i-1]){
			st=i;
			break;
		}
	}
	for (int i=n;i>=1;i--){
		if (A[i-1]!=B[i-1]){
			ed=i;
			break;
		}
	}
	ans=0;
	for (int i=1;i<=st;i++){
		string tempA="",tempB="";
		for (int j=i;j<ed;j++){
			tempA=tempA+A[j-1];
			tempB=tempB+B[j-1];
		}
		for (int j=ed;j<=n;j++){
			tempA=tempA+A[j-1];
			tempB=tempB+B[j-1];
			if (has[tempA][tempB]){
				ans++;
			}
		}
	}
	printf("%lld\n",ans);
	return;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	init();
	for (int i=1;i<=q;i++){
		solve();
	}
	return 0;
}
