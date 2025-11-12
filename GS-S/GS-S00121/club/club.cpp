#include <bits/stdc++.h>
using namespace std;
struct node{
	long long a,b,c,d;
}arr[100005];
bool cmp1(node x,node y){return min(x.a - x.b,x.a - x.c) < min(y.a - y.b,y.a - y.c);}
bool cmp2(node x,node y){return min(x.b - x.a,x.b - x.c) < min(y.b - y.a,y.b - y.c);}
bool cmp3(node x,node y){return min(x.c - x.b,x.c - x.a) < min(y.c - y.b,y.c - y.a);}
long long i1,i2,i3,ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t,n;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		memset(arr,0,sizeof(arr));
		i1 = i2 = i3 = ans = 0;
		for(long long i = 1;i <= n;i++){
			scanf("%lld%lld%lld",&arr[i].a,&arr[i].b,&arr[i].c);
			if(arr[i].a >= arr[i].b && arr[i].a >= arr[i].c){
				arr[i].d = 1;
				i1++;
				ans += arr[i].a;}
			else if(arr[i].b >= arr[i].a && arr[i].b >= arr[i].c){
				arr[i].d = 2;
				i2++;
				ans += arr[i].b;}
			else{
				arr[i].d = 3;
				i3++;
				ans += arr[i].c;}}
		if(max(max(i1,i2),i3) > n / 2){
			if(i1 > n / 2){
				sort(arr+1,arr+n+1,cmp1);
				for(int i = 1;i <= n && i1 > n / 2;i++){
					if(arr[i].d == 1){
						if(arr[i].b > arr[i].c){
							i1--;
							i2++;
							ans -= arr[i].a;
							ans += arr[i].b;
							arr[i].d = 2;}
						else{
							i1--;
							i3++;
							ans -= arr[i].a;
							ans += arr[i].c;
							arr[i].d = 3;}}}}
			else if(i2 > n / 2){
				sort(arr+1,arr+n+1,cmp2);
				for(int i = 1;i <= n && i2 > n / 2;i++){
					if(arr[i].d == 2){
						if(arr[i].a > arr[i].c){
							i2--;
							i1++;
							ans -= arr[i].b;
							ans += arr[i].a;
							arr[i].d = 1;}
						else{
							i2--;
							i3++;
							ans -= arr[i].b;
							ans += arr[i].c;
							arr[i].d = 3;}}}}
			else{
				sort(arr+1,arr+n+1,cmp3);
				for(int i = 1;i <= n && i1 > n / 3;i++){
					if(arr[i].d == 3){
						if(arr[i].b > arr[i].a){
							i3--;
							i2++;
							ans -= arr[i].c;
							ans += arr[i].b;
							arr[i].d = 2;}
						else{
							i3--;
							i1++;
							ans += arr[i].a;
							ans -= arr[i].c;
							arr[i].d = 1;}}}}}
		printf("%lld\n",ans);}
	fclose(stdin);
	fclose(stdout);
	return 0;}
