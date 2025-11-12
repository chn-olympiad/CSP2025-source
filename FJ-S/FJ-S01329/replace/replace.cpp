#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 2e5 + 10;
int n,q;
string s1[N],s2[N];
int d[N];
int res;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i = 1;i <= n;i ++){
		cin >> s1[i] >> s2[i];
	}
	while(q --){
		string start,end;
		cin >> start >> end;
		string t = start;
		int res = 0;
		for(int i = 1;i <= n;i ++){
			int f = t.find(s1[i]);
			if(f < n){
				for(int j = 0;j < s1[i].size();j ++){
					t[f + j] = s2[i][j];
				}
				if(t == end) res ++;
			}
			t = start;
		}
		printf("%d\n",res);
	}
	return 0;
}
