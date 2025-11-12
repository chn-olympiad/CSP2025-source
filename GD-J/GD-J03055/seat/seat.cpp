#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int num[110];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	int le = n*m;
	for(int i =1;i<=le;i++) scanf("%d",&num[i]);
	sort(num+2,num+le+1,cmp);
	if(m == 1){
		sort(num+1,num+le+1,cmp);
		for(int i = 1;i<=le;i++){
			cout<<num[i];
		}
	}
	for(int i =2;i<=le;i++){
		if(i+1 <= le){
			if(num[i]>num[1] && num[i+1]<num[1]){
				int lie = (i%n==0) ? i/n : i/n+1;
				int hang = (i+1)%n;
				if((lie % 2) == 0){
					if(hang == 1) printf("%d %d",lie,1);
					else if(hang == 0) printf("%d %d",lie,2);
					else printf("%d %d",lie,n-hang+2);
					break;
				}else{
					if(lie != 1){
						if(hang == 1) printf("%d %d",lie,m);
					    else if(hang == 0) printf("%d %d",lie,m-1);
					    else printf("%d %d",lie,hang-1);
					    break;
					}else{
						printf("%d %d",1,i);
						break;
					}
				}
			}
		}else{
			int lie = ceil((i+1)/n);
			int hang = (i+1)%n;
			if(num[0]>num[i]){
				if(lie % 2 == 0){
					printf("%d %d",n,2);
				}else{
					printf("%d %d",n,m-1);
				}
			}else{
				if(lie % 2 == 0){
					printf("%d %d",n,1);
				}else{
					printf("%d %d",n,m);
				}
			}
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
