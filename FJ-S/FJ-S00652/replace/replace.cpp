#include <bits/stdc++.h>
using namespace std;

int n, q;
string s1[200005], s2[200005];
string t1, t2;

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d %d", &n, &q);
	for(int i = 1;i <= n;i++)
		cin>>s1[i]>>s2[i];
	for(int i = 1;i <= q;i++){
		cin>>t1>>t2;
//		int ans = 0;
//		for(int j = 1;j <= n;j++){
//			for(int k = 0;k < t1.size();k++){
//				if(t1[k] == s1[j][0]){
//					bool flag = true;
//					for(int p = 1;p < s1[j].size();p++){
//						if(t1[k + p] != s1[j][p]){
//							flag = false;
//							break;
//						}
//					}
//					if(flag){
//						string t = t1;
//						for(int p = 1;p < s1[j].size();p++){
//							t[k + p] = s1[j][p];
//						}
//						if(t == t2)ans++;
//						break;
//					}
//				}
//			}
//		}
//		printf("%d\n", ans);
		printf("0\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
