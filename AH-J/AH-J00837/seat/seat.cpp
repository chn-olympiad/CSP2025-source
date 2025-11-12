#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,nowx=1,nowy=1;
bool flag=true;
int a[305];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	cnt=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(flag && nowy==n+1){
			flag=false;
			nowy=n;
			nowx++;
			if(a[i]==cnt){
				printf("%d %d\n",nowx,nowy);
				break;
			}
			nowy--;
		}else if(!flag && nowy==0){
			flag=true;
			nowx++;
			nowy=1;
			if(a[i]==cnt){
				printf("%d %d\n",nowx,nowy);
				break;
			}
			nowy++;
		}
		else{
			if(a[i]==cnt){
				printf("%d %d\n",nowx,nowy);
				break;
			}
			if(flag) nowy++;
			else nowy--;
		}
	}
	return 0; 
}
