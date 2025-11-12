#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,maxt[N];
int a[N][4];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				maxt[i]=a[i][1];
			}
		} 
		if(n==2){
			int max1=-1,id1,max2=-1;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					if(i==1 && max1<a[i][j]){
						max1=a[i][j];
						id1=j;
					}
				}
				for(int j=1;j<=3;j++){
					if(i==2 && j!=id1 && max2<a[i][j]){
						max2=a[i][j];
					}
				}
			} 
			cout<<max1+max2<<endl;
		}else{
			sort(maxt+1,maxt+1+n,cmp);
			int summ=0;
			for(int i=1;i<=n/2;i++){
				summ+=maxt[i];
			} 
			cout<<summ<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
