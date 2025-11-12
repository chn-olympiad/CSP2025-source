#include<bits/stdc++.h>
using namespace std;
int arr[105];
int sr,n,m;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int len = n * m;
	for(int i = 1;i<=len;i++)
		scanf("%d",&arr[i]);
	sr = arr[1];
	sort(arr+1,arr+len+1,cmp);
	for(int i = 1;i<=len;i++){
		if(arr[i] == sr){
			int l,h;
			l = (i % n == 0 ? i / n: i / n + 1);
			h = (l % 2 == 0 ? n - (i % n) + 1: (i - 1) % n + 1);
			printf("%d %d",l,h);
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
