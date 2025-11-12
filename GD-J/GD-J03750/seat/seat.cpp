#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[109];
int Stu;
int Mpon;
int Msea;
int Hang;
bool cmp(int a,int b){
	return a > b;
}
int main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout)
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	Stu = n * m;
	for(int i = 1;i <= Stu;i++){
		scanf("%d",&a[i]);
	}
	Mpon = a[1];
	sort(a+1,a+Stu+1,cmp);
	for(int i = 1;i <= Stu;i++){
		if(Mpon == a[i]){
			Msea = i;
			break;
		}
	}
	Msea%n!=0?Hang=Msea/n+1:Hang = Msea/n;
	printf("%d ",Hang);
	if(Hang % 2 == 0){
		if(Msea%n==0){
			printf("1");
		}
		else{
		    printf("%d",n-(Msea%n)+1);
		}
	}
	else{
		if(Msea%n==0){
			printf("%d",n);
		}
		else{
		    printf("%d",Msea%n);
		}
	}
	return 0;
}
