#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int a[1010010][5];
int s=0;
int q_1,q_2,q_3;
int h_1,h_2,h_3;
int h_13,h_23,h_33;
int aa,bb,cc;
int f(int x){
		
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int k=1;k<=T;k++){
		cin>>n;
		int h_1=0,h_2=0,h_3=0;
		int h_13=0,h_23=0,h_33=0;
		q_1=n/2,q_2=n/2,q_3=n/2;
		s=0;
		for(int i=1;i<=n;i++){
			a[i][0]=1;
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		
		}
		//cout<<h_1<<" "<<h_2<<" "<<h_3<<endl;
		for(int i=1;i<=n/3+1;i++){
			for(int i=1;i<=n;i++){
				if((a[i][1]>h_1&&a[i][0]==1)){
					a[h_13][0]=1;
					h_13=i;
					h_1=a[i][1];
					a[i][0]=0;
				}if((a[i][2]>h_2&&a[i][0]==1)){
					a[h_23][0]=1;
					h_23=i;
					h_2=a[i][2];
					a[i][0]=0;
				}if((a[i][3]>h_3&&a[i][0]==1)){
					a[h_33][0]=1;
					h_33=i;
					h_3=a[i][3];
					a[i][0]=0;
				}
			}
			cout<<h_1<<" "<<h_2<<" "<<h_3<<endl;
			if(h_1!=aa&&q_1>0){
				q_1-=1;
				s+=h_1;
			}if(h_2!=bb&&q_2>0){
				q_2-=1;
				s+=h_2;
			}if(h_3!=cc&&q_3>0){
				q_3-=1;
				s+=h_3;
			}
			aa=h_1;
			bb=h_2;
			cc=h_3;
		//	cout<<s<<endl;
			}
			cout<<s<<endl;
	}
	
	return 0;
}
//   1 2 3 4    1 2 3 4 
//1  4 3.5.3  1 0 0 0 0
//2  2 2 3 5  2 1 1 2 2
//3  1 4 4 1  3 0 0 0 0
