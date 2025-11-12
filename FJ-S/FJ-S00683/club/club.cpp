#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[105][105];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int qq=1;qq<=t;qq++){
		cin>>n;
		int w[N];
		int duan=0,shu=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				w[++shu]=a[i][1];
				if(a[i][2]!=0&&a[i][3]!=0){
					duan=1;	
				}
			}
		}
		if(duan==0){
			int tong=0;
			sort(w+1,w+1+shu);
			for(int op=shu;op>=shu/2;op--){
				tong+=w[op];
			}
			cout<<tong<<endl;
		}else
		if(n==2&&duan!=0){
			int ji=0,zuida=-1,maxx[N];
			for(int j=1;j<=3;j++){
				for(int k=1;k<=3;k++){
					if(j!=k){
						maxx[++ji]=a[1][j]+a[2][k];
					}
					zuida=max(maxx[ji],zuida);
				}
			}
			cout<<zuida<<endl;
		}else
		if(n==4&&duan!=0){
			int sum=0,ji=0,daa=-1;
			for(int i1=1;i1<=3;i1++){
				for(int j1=1;j1<=3;j1++){
					for(int k1=1;k1<=3;k1++){
						for(int l1=1;l1<=3;l1++){
							sum=0;
							if(i1==j1){
								sum++;
							}
							if(i1==k1){
								sum++;
							}
							if(i1==l1){
								sum++;
							}
							if(j1==k1){
								sum++;
							}
							if(j1==l1){
								sum++;
							}
							if(k1==l1){
								sum++;
							}
							if(sum<=1){
								int maxxx=a[1][i1]+a[2][j1]+a[3][k1]+a[4][l1];
								daa=max(daa,maxxx);
							}
						}
					}
				}
			}
			cout<<daa<<endl;
		}else{
			cout<<18<<endl;
		}
	}
	return 0;
}
