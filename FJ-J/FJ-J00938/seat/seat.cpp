#include<iostream>
#include<algorithm>
using namespace std;
const int N=105;
int n,m;
int arr[N];
int brr[N][N];
int cmp(int a,int b){
	return a>b;
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int len=n*m;
	for(int i=1;i<=len;i++){
		scanf("%d",&arr[i]);
	}
	int a=arr[1];
	sort(arr+1,arr+len+1,cmp);
	int s=0;
	for(int i=1;i<=len;i++){
		if(arr[i]==a){
			s=i;
			break;
		}
	}
	int b=0;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				brr[i][j]=++b;
			}
		}
		if(j%2==0){
			for(int i=n;i>=1;i--){
				brr[i][j]=++b;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
//			cout<<brr[i][j]<<" ";
			if(brr[i][j]==s){
				printf("%d %d",j,i);
				return 0;
			}
		}
//		cout<<endl;
	}
	return 0;
}
