#include<bits/stdc++.h>
using namespace std;
int n,m;
int a_chen[15][15],cnt_chen[155];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>cnt_chen[i];
	}
	int xiaoR=cnt_chen[1];
	sort(cnt_chen+1,cnt_chen+n*m+1,cmp);
	int i=1,j=1; bool flag_ch=false;
	for(int cnt_91=1;cnt_91<n*m;){
		if(i+1>n){
			a_chen[i][j]=cnt_chen[cnt_91];
			j++;
			flag_ch=true;
			cnt_91++;
		}if(i-1==0&&cnt_91!=1){
		a_chen[i][j]=cnt_chen[cnt_91];
			j++;
			flag_ch=false;
			cnt_91++;
			
		}
		if(flag_ch==true){ 
			/*if(cnt_chen[cnt_91]==xiaoR){
				cout<<i<<" "<<j;
				//return 0;
			}*/
			a_chen[i][j]=cnt_chen[cnt_91];
			i--; cnt_91++;
		}
		if(flag_ch==false){
			a_chen[i][j]=cnt_chen[cnt_91];
			i++; cnt_91++;
		}
	}
	a_chen[i][j]=cnt_chen[n*m];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a_chen[i][j]==xiaoR){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}
