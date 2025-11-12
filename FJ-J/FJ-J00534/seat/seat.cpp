#include<bits/stdc++.h>
using namespace std;

int n,m,a[101],R,n1=0,m1=1,ans;
bool flag;
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
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			ans=i;
			break;
		}
	}
	for(int i=1;i<=ans;i++){
		if(flag==0&&n1==n){
			flag=1;
			m1++;
		}
		else{
			if(flag==1&&n1==1){
				m1++;
				flag=0;
			}
			else{
				if(flag==0) n1++;
				else n1--;
			}
		}	
	}
	printf("%d %d",m1,n1);
	return 0;
}
