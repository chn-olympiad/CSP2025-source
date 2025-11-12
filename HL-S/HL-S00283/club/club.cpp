#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int T,a,b,c,n;
int s1[maxn][4];
int ma[maxn];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		int k=0;
		for(int i =0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>s1[i][j];
				if(j==0){
					ma[k]=s1[i][j];
					k++;
				}
				
			}
		}
		sort(ma,ma+k);
		int tot=0;
		for(int i =k/2;i<k;i++){
			tot+=ma[i];
		}
		cout<<tot;
	}
	
	return 0; 
} 
/*
1
6
1 0 0
2 0 0
3 0 0
4 0 0
5 0 0
6 0 0
*/
