#include<bits/stdc++.h>
using namespace std;
int n ,q;
int x = 1;
int cnt = 0;
struct node{
	string s1;
	string s2;
}str1[2 * 100005],str2[2*100005];
int ans[2*100005];
char tong[2*100005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
		cin >> str1[i].s1 >> str1[i].s2;
	for(int i = 1;i <= q;i++)
		cin >>  str2[i].s2 >> str2[i].s2;
	
	for(int i = 1;i <= q;i++){
		for(int j = 1;j <= str2[i].s1.size();j++)
			if(str2[i].s2[j] != str2[i].s1[j]){
				cnt++;tong[x++] = j;
			}
	}
	if(cnt > 1)
		cout << 0 << endl;
	return 0;
}
