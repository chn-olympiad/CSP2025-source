#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,cnt=0,d1=0,d2=0,d3=0,a1=0,a2=0,a3=0;
	cin>>t>>n;
	int p=n/2;
	if(n<=2||n%2!=0){
		return 0;
	}
	for(int q=0;q<t;q++){
		for(int i=0;i<=n;i++){
			for(int j=0;j<=3;j++){
				cin>>a1>>a2>>a3;
				if(a1>a2&&a1>a3){
					if(d1<=p){
						d1++;
						cnt+=a1;
					}
					else if(a1==0&&a2==0){
						cnt+=a3;
					}
					else if(a1==0&&a3==0){
						cnt+=a2;
					}
					else if(a2==0&&a3==0){
						cnt+=a1;
					}
				}
				else if(a2>a1&&a2>a3){
					if(d2<=p){
						d2++;
						cnt+=a2;
					}
					else if(a1==0&&a2==0){
						cnt+=a3;
					}
					else if(a1==0&&a3==0){
						cnt+=a2;
					}
					else if(a2==0&&a3==0){
						cnt+=a1;
					}
				}
				else if(a3>a2&&a3>a1){
					if(d3<=p){
						d3++;
						cnt+=a3;
					}
					else if(a1==0&&a2==0){
						cnt+=a3;
					}
					else if(a1==0&&a3==0){
						cnt+=a2;
					}
					else if(a2==0&&a3==0){
						cnt+=a1;
					}
				}
			}
		cout<<cnt<<endl;
		cnt=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
Ren5Jie4Di4Ling5%

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

18
4
13
*/
