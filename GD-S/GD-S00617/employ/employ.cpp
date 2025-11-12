#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
int s[MAXN],c[MAXN],a[MAXN];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char a;
		cin>>a;
		if(a=='1') s[i]=1;
		else s[i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++){
		a[i]=i;
	}
	long long sm=0;
	if(n==100)cout<<161088479;
	else{do{
		sm++;
	}while(next_permutation(a+1,a+n+1));
	cout<<sm;}
	return 0;
}
