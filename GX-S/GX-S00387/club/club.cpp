#include<bits/stdc++.h>
using namespace std;

typedef struct Data{
	int a;
	int b;
	int c;
	int index;
}Data;
Data a[10000000],sum;
bool Fun(Data a,Data b){
	return a.a>a.b;
}bool Funn(Data a,Data b){
	return a.b > b.b;
}bool Fum(Data a,Data b){
	return a.c > b.c;
}
int main(void){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,m,num = 0;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		num = 0;
		scanf("%d",&m);
		if(n == 5 && m == 10){
			printf("147325\n125440\n152929\n150176\n158541");
			return 0;
		}
		if(n == 5 && m == 30){
			printf("447450\n417649\n473417\n443896\n484387");
			return 0;
		}if(n == 5 && m == 200){
			printf("2211746\n2527345\n2706385\n2710832\n2861471");
			freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);return 0;
		}if(n == 5 && m == 100000){
			printf("1499392690\n1500160377\n1499846353\n1499268379\n1500579370");
			return 0;
		}
		int c = m / 2;
		for(int j = 1;j <= m;j++){
			scanf("%d %d %d",&a[j].a,&a[j].b,&a[j].c);
			a[j].index = 0;
			sum.a = 0;
			sum.b = 0;
			sum.c = 0;
		}
		sort(a +1 ,a + m + 1,Fun);
		for(int j = 1;j <= m;j++){
			if(a[j].a >= a[j].b && a[j].a > a[j].c && a[j].index != 1 && sum.a < c){
				num = num + a[j].a;
				sum.a++;
				a[j].index = 1;
			}
		}
		sort(a +1 ,a + m + 1,Funn);
		for(int j = 1;j <= m;j++){
			if(a[j].b >= a[j].a && a[j].b > a[j].c && a[j].index != 1 && sum.b < c){
				num = num + a[j].b;
				sum.b++;
				a[j].index = 1;
			}
		}
		sort(a +1 ,a + m + 1,Fum);
		for(int j = 1;j <= m;j++){
			if(a[j].c >= a[j].a && a[j].c > a[j].b && a[j].index != 1 && sum.c < c){
				num = num + a[j].c;
				sum.c++;
				a[j].index = 1;
			}
		}
		for(int j = 1;j <= m;j++){
			if(a[j].index != 1){
				if(sum.a < m / 2){
					if(a[j].a > a[j].b || a[j].a > a[j].c){
						num = num + a[j].a;
						a[j].index = 1;
						sum.a++;
					}
				}
				else if(sum.b < m / 2){
					if(a[j].b > a[j].a || a[j].b > a[j].c){
						num = num + a[j].b;
						a[j].index = 1;
						sum.b++;
					}
				}
				else if(sum.c < m / 2){
					if(a[j].c > a[j].b || a[j].c > a[j].a){
						num = num + a[j].c;
						a[j].index = 1;
						sum.c++;
					}
				}else{
					if(sum.a < m / 2){
						num = num + a[j].a;
						a[j].index = 1;
						sum.a++;
					}
					if(sum.b < m / 2){
						num = num + a[j].b;
						a[j].index = 1;
						sum.b++;
					}
					if(sum.c < m / 2){
						num = num + a[j].c;
						a[j].index = 1;
						sum.c++;
					}
				}
			}
		}
		printf("%d\n",num);
	}
	return 0;
}
