#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N = 1e4 + 5;
int n,m,a[N];
string s;
ll sum;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    cin >> s;
	for(int i = 1 ; i <= n ; i++){
		scanf("&d",&a[i]);
		if(a[i]!=0){
			sum++;
		}
	}
	if(sum == m){
		printf("1");
	}
	else{
		printf("0");
	}
	return 0;
}
