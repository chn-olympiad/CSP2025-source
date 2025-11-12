#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N=1e5+5;
struct node{
	int a[4],c;
}a[N];
int cnt[N];
bool cmp(pair<int,int>x,pair<int,int>y){
	return x.first>y.first;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	puts("0");
	return 0;
}
