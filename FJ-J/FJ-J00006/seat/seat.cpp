#include<bits/stdc++.h>
using namespace std;
//vector<int>a;push_back(1);
//priority_queue<int>a;
bool cmp(int a,int b){
	return a>b;
}
int a[110];
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&m,&n);
	int len=n*m;
	int R=0;
	for(int i=1;i<=len;i++){
		scanf("%d",&a[i]);
		if(i==1)R=a[i];
	}
	sort(a+1,a+len+1,cmp);
	int k=1;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				if(a[k]==R){
					printf("%d %d",i,j);
					return 0;
				}
				k++;
			}
		}
		else{
			for(int j=m;j>=1;j--){
				if(a[k]==R){
					printf("%d %d",i,j);
					return 0;
				}
				k++;
			}
		}
	}
	return 0;
}
