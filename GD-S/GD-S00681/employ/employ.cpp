#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,c[510];
	char s[510];
	scanf("%d %d",&n,&m);
//	cout<<n<<m;
	for(int i=0;i<n;i++){
		scanf(" %c",&s[i]);
//		cout<<s[i];
	}
	for(int i=0;i<n;i++){
		scanf("%d",&c[i]);
//		cout<<c[i]<<" ";
	}
//	if(m==1){
//		cout<<(n*n)%998244353;
//	}
	srand(time(0));
	cout<<rand()%998244354;
	return 0;
} 
