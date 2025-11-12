#include<bits/stdc++.h>
//Ren5Jie4Di4Ling5%
using namespace std;
struct s1{
	int value;
	int xb;
};
s1 a[10000][3];
int n,m;
int cot=0;
int b[4];
bool cmp(s1 x,s1 y){
	return x.value>y.value;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m;
		for(int j=1;j<=m;j++){
			for(int k=0;k<3;k++){
				cin>>a[j][k].value;
				a[j][k].xb=k;
				b[i+1]=n/2;
			}
		}
		for(int i=1;i<=m;i++){
			sort(a[i],a[i]+3,cmp);
		}
		for(int i=1;i<=m;i++){
			for(int j=i;j<=m;j++){
				if(a[i][0].value<a[j][0].value)swap(a[i],a[j]);
			}
		}
		
		for(int i=0;i<m;i++){
			if(b[a[i][0].xb]>0){
				b[a[i][0].xb]--;
				cot+=a[i][0].value;
			}
			else if(b[a[i][1].xb]>0){
				b[a[i][1].xb]--;
				cot+=a[i][1].value;
			} 
			else{
				cot+=a[i][2].value;
			}
		}
		}
		cout<<cot<<endl;
	}
