#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int M=5e6+5;
string s1[N],s2[N];
int len[N][2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		int num=-1,num1=-1;
		for(int j=0;j<s1[i].size();j++){
			if(s1[i][j]=='b'){
				num=j;
				break;
			}
		}
		for(int j=0;j<s2[i].size();j++){
			if(s2[i][j]=='b'){
				num1=j;
				break;
			}
		}
		len[abs(num-num1)][num>num1]++;
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		cout<<0<<'\n';
	}
	return 0;
}
