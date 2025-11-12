#include<iostream>
#include<algorithm>
#define MAXN 1100000
#define IO(x) freopen(#x ".in","r",stdin); freopen(#x ".out","w",stdout);
using namespace std;
string S;
int G[MAXN],Num=0;
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> S;
	int n=S.size();
	S=" "+S;
	for(int i=1;i<=n;i++){
		if(S[i]>='0'&&S[i]<='9'){
			int num=S[i]-'0';
			G[++Num]=num;
		}
	}
	sort(G+1,G+n+1,cmp);
	for(int i=1;i<=Num;i++)cout << G[i];
	return 0;
}