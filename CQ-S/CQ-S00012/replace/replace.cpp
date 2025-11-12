#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[10005][5];
struct node{
	int x;
	int a1,a2,a3;
}b[10005][10005];
int x1,x2,x3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m;
		for(int j=1;j<=n;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			dt();
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
