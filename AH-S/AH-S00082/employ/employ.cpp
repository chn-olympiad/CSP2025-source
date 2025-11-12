#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
int n,m;
long long cnt,mod=998244353;
long long a[1000005],b[1000005];
bool tong[1000005];
long long df[1000005];
bool check (){	
	int out=0,pass=0;
	for (int i=1;i<=n;i++){
		if (a[i]==0||out>=b[df[i]]) out++;
		else pass++;
	}
	if (pass>=m) return 1;
	else return 0;
}
void work(int tp){
	if (tp==n+1){
		memset(tong,0,sizeof(tong));
		int ok=1;
		for (int i=1;i<=n;i++){
			if (tong[df[i]]==1){
				ok=0;
				break;
			}
			tong[df[i]]=1;
		}
		if (ok&&check()) cnt++;
		return ;
	}
	for (int i=1;i<=n;i++){
		df[tp]=i;
		work(tp+1);
	}
}
int main (){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >>n>>m;
	for (int i=1;i<=n;i++){
		char c;
		cin >>c;
		a[i]=c-48;
	}
	for (int i=1;i<=n;i++)
		cin >>b[i];
	if (n<=20){
		work(1);
		cout <<cnt<<endl;
		return 0;
	}
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
