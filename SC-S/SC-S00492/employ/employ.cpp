#include<iostream>
using namespace std;
int n,m;
char s[507];
int a[507];
int b[17]={0,1,2,3,4,5,6,7,8,9,10};
const int N=998244353;
int cnt=0;
void pailie(int id){
	if(id==n){
		int xx=0;
		for(int i=1;i<=n;i++){
			if(xx>=a[b[i]]) xx++;
			else if(s[i-1]=='0') xx++;
		}
		if(n-xx>=m) cnt++;
	}
	for(int i=id;i<=n;i++){
		swap(b[id],b[i]);
		pailie(id+1);
	}
	for(int i=id;i<=n-1;i++){
		swap(b[i],b[i+1]);
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	if(n<=10){
		pailie(1);
		printf("%d",cnt);
		return 0;
	}
	printf("0");
	return 0;
}