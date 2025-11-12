#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
bool ft[505];
int a[505];
int id[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d%d\n",&n,&m);
	for(int i=1;i<=n;i++){
		ft[i]=(getchar()=='0');
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		id[i]=i;
	}
	int s=0;
	m=n-m;
	do{
		int pre=0;
		for(int i=1;i<=n;i++){
			if(pre>=a[id[i]]||ft[i]){
				pre++;
			}
		}
		if(pre<=m){
			s++;
			if(s>=p){
				s-=p;
			}
		}
	}while(next_permutation(id+1,id+n+1));
	cout<<s;
}
