#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[123];
bool cmp(int cmpx,int cmpy){
	return cmpx>cmpy;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int NM=n*m;
	for (int i=1;i<=NM;i++){
		scanf("%d",&a[i]);
	}
	int R=a[1];
	sort(a+1,a+NM+1,cmp);
	int Num=1;
	for (int i=1;i<=NM;i++){
		if (a[i]==R)Num=i;
	}
	int lie=ceil(Num*1.0/n);
	int hang=1;
	if (lie%2==1){
		hang=Num%n;
		if (hang==0)hang=n;
	}else{
		int yushu=Num%n;
		hang=n-yushu+1;
		if (hang>n)hang=hang%n;
		if (hang==0)hang=n;
	}
	printf("%d %d",lie,hang);
	return 0;
}

