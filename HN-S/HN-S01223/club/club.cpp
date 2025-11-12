#include<bits/stdc++.h> 
using namespace std;
int n,a[100010][5],l[100010];
long long b,r[50010][5],z;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>b;
		z=0;
		int m=b/2;
		int club[50010]={0};
		for(int i=1;i<=b;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			l[i]=a[i][1];
		}
		sort(l,l+b+1);
		for(int i=b;i>=1;i--){
			if(club[1]<m){
				z+=l[i];
				club[1]++;
			}
		}
		cout<<z<<endl;
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
