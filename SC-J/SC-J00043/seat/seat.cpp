/**
 * @file seat.cpp 
 * @version:  1.2.0
 * @author: dpl
 * @date: 2025-11-01 10:40:13
 * 
 **/
#include<bits/stdc++.h>
using namespace std;
int n,m,a[200];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int cj=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int posx=1,posy=1,flag=1;
	for (int i=1;i<=n*m;i++){
		if (a[i]==cj){
			printf("%d %d",posy,posx);
			return 0;
		}
		if (flag==1&&posx+1<=n){
			posx+=1;
			continue;
		}
		if (flag==1&&posx+1>n){
			posy++;
			flag=0;
			continue;
		}
		if (flag==0&&posx-1>=1){
			posx--;
			continue;
		}
		if (flag==0&&posx-1<n){
			posy++;
			flag=1;
			continue;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}