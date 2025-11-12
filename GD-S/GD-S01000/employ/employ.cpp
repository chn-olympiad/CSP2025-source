#include<bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int N=505;
int n,m,cnt=0,c[N],order[N];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		order[i]=i;
	}
	do{
		int k=0,tot=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'||k>=c[order[i]]){
				k++;
				continue;
			}
			tot++;
			if(tot>=m){
				cnt++;
				break;
			}
		}
	}while(next_permutation(order+1,order+n+1));
	cout<<cnt<<'\n';
	return 0;
}
/*
note:
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/

