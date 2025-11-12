#include <bits/stdc++.h>
using namespace std;
struct Student{
	int chengji;
	int shunxu;
};
bool cmd(Student a,Student b){
	if((a.chengji)!=(b.chengji)){
		return (a.chengji)>(b.chengji);
	}else if(a.chengji==b.chengji){
		return (a.shunxu)<(b.shunxu);
	}
}
int c(int a,int b){
	if(a%b==0){
		return a/b;
	}else{
		return a/b+1;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=0,m=0;
	int R=0;
	Student s[105]={0};
	int fs_num[105]={0};
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		int a=0;
		scanf("%d",&a);
		s[i].chengji=a;
		s[i].shunxu=i;
	}
	
	sort(&s[1],&s[n*m+1], cmd);
	
	for(int i=1;i<=n*m;i++){
		if(s[i].shunxu==1){
			R=i;
			break;
		}
	}
	
	if(c(R,n)%2==1){
		if(R%n==0){
			printf("%d %d",c(R,n),n);
		}else{
			printf("%d %d",c(R,n),R%n);
		}
	}else{
		if(R%n==0){
			printf("%d %d",c(R,n),1);
		}else{
			printf("%d %d",c(R,n),n+1-R%n);
		}
	}
	return 0;
}/*3 3
94 95 96 97 98 99 100 93 92
*/
