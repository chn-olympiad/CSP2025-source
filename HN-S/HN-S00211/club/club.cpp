#include<bits/stdc++.h>
using namespace std;
struct stu{
	int h1, h2, h3;
}a[100005];
bool cmp(stu x, stu y){
	if(x.h1 == y.h1){
		if(x.h2 == y.h2){
			return x.h3 > y.h3;
		}
		return x.h2 > y.h2;
	}
	return x.h1 > y.h1;
}
int t, n;
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			scanf("%d %d %d", &a[i].h1, &a[i].h2, &a[i].h3);
		}	
		sort(a+1, a+n+1, cmp);
//		for(int i = 1; i <= n; i++){
//			printf("%d %d %d\n", a[i].h1, a[i].h2, a[i].h3);
//		}
		int s1,s2,s3;
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
} 
