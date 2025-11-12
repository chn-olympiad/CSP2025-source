#include <bits/stdc++.h>
using namespace std;
int a[200];
int p;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int nm=n*m;
	int me=a[1];//我的分数
	sort(a+1,a+1+nm);
	int x=0,y=0,ren=nm;//现在的位置 第几个人 
	int ans_x,ans_y;
	for(int i=1;i<=m;i++){//列 
		for(int j=1;j<=n;j++){//行
			if(i%2==1){
				if(j==n) x=x;
				else x++;
			}
			if(i%2==0){
				if(j==1) x=x;
				else x--;
			}
			if(a[ren]==me){
				ans_x=i;
				ans_y=x;
			}
			ren--;
		}
	}
	cout<<ans_x<<' '<<ans_y;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
