#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,m,cnt;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int nm=n*m;
	for(int i=1;i<=nm;i++){
		scanf("%d",&a[i]);
	}
	int head=a[1];
	sort(a+1,a+nm+1);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[nm]==head){
				if(i%2!=0){
					printf("%d %d",i,j);
					return 0;
				}
				else{
					printf("%d %d",i,(n-j+1));
					return 0;
				}
			}
			nm--;
		}
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
