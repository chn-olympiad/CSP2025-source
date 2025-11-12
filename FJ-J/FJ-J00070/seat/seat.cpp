#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int b[150];//分数 
int a[20][20];//座位 
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;//列   行
	for(int i=1;i<=n*m;i++){
		cin>>b[i];//输入分数 
	}
	int x=b[1];//小R分数 
	sort(b+1,b+1+n*m,cmp);//分数排序 
	int cnt=0;//计算排到第几个 
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cnt++; 
			if(i%2==1){//奇数列行加 
				a[j][i]=b[cnt];
			}
			if(i%2==0){//偶数列行减 
				a[n+1-j][i]=b[cnt];
			}
		}
	}
	cnt=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cnt++; 
			if(i%2==1){//奇数列行加 
				if(a[j][i]==x){
					cout<<i<<" "<<j;
					return 0;
				}
			}
			if(i%2==0){//偶数列行减 
				if(a[n+1-j][i]==x){
					cout<<i<<" "<<n+1-j;
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
