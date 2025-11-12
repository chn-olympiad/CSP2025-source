#include <bits/stdc++.h>
using namespace std;
char s1[3000][3000], s2[3000][3000], a[5000005], b[5000005], c[5000005];
int n, m;
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++){
		scanf("%s %s", s1[i]+1, s2[i]+1);
	}  
	for(int i=1; i<=m; i++){
		int a1=0, b1=0, l=0, r=0;
		scanf("%s %s", a+1, b+1);
		for(int i=1; a[i]; i++)
		    a1++;
		for(int i=1; b[i]; i++)
		    b1++;
		if(a1!=b1)
		    printf("0\n");
		else{
			for(int i=1; i<=a1; i++){
				if(a[i]!=b[i])
				   l=i;
			}
			for(int i=a1; i>=0; i--){
				if(a[i]!=b[i])
				   r=i;
			}
			int ans=0;
			for(int i=l; i<=r; i++){
				
				if(c==b)
				   ans++;
			}
			printf("%d\n", ans);
		}
	}
    return 0;
}
