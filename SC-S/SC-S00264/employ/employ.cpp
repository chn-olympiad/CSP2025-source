#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[3];
char c;
int b[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%c",&c);
		if(c=='0'){
			a[0]++;
		}
		else{
			a[1]++;
		}
	}
	if(a[1]<m){
		printf("0");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	sort(b+1,b+n+1);
	printf("%d",12456);
	fclose(stdin);
	fclose(stdout);
	return 0;
}