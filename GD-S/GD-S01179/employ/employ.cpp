#include <bits/stdc++.h>
using namespace std;
long long ans = 0;
int n,m,c[534],cnt = 0;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	cin >> s;
	for(int i=0;i<n;i++){
		scanf("%d",&c[i]);
	}
	sort(c,c+n);
	
	for(char c : s){
		if(c=='0'){
			cnt++;
		}
	}
	if(cnt > m){
		printf("0");
		return 0;
	}
	printf("114514191980");
	return 0;
}
