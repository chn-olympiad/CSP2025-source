#include<bits/stdc++.h>
using namespace std;
int t,n,a[100000][3],b[100000][3][3],s[3],m,h,m1,l1;
long long sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		s[0]=0,s[1]=0,s[2]=0,sum=0;
		cin>>n;
		for(int l=0;l<n;l++){
			m=0,m1=0;
			for(int j=0;j<3;j++){
				cin>>a[l][j];
				if(a[l][j]>m){
					m=a[l][j];
					h=j;
				}else if(a[l][j]>m1){
					m1=a[l][j];
				}
			}
			a[l][3]=m-m1;
			b[s[h]][0][h]=m-m1;
			b[s[h]][1][h]=l;
			b[s[h]][2][h]=m;
			for(int k=s[h]-1;k>=0;k--){
				if(m-m1>b[k][0][h]){
					b[k+1][0][h]=b[k][0][h],b[k+1][1][h]=b[k][1][h],b[k+1][2][h]=b[k][2][h];
					b[k][0][h]=m-m1,b[k][1][h]=l,b[k][2][h]=m;
				}else{
					break;
				}
			}
			s[h]++;
			if(s[h]>n/2){
				s[h]--;
				l1=b[s[h]][1][h];
				b[s[h]][0][h]=0,b[s[h]][1][h]=0,b[s[h]][2][h]=0;
				if(((a[l1][0]>=a[l1][1]&&a[l1][0]<=a[l1][2])||(a[l1][0]>=a[l1][2]&&a[l1][0]<=a[l1][1]))&&h!=0){
					b[s[0]][0][0]=a[l1][3],b[s[0]][1][0]=l1,b[s[0]][2][0]=a[l1][0];
					s[0]++;
				}else if(((a[l1][1]>=a[l1][0]&&a[l1][1]<=a[l1][2])||(a[l1][1]>=a[l1][2]&&a[l1][1]<=a[l1][0]))&&h!=1){
					b[s[1]][0][1]=a[l1][3],b[s[1]][1][1]=l1,b[s[1]][2][1]=a[l1][1];
					s[1]++;
				}else{
					b[s[2]][0][2]=a[l1][3],b[s[2]][1][2]=l1,b[s[2]][2][2]=a[l1][2];
					s[2]++;
				}
			}
		}
		for(int x=0;x<3;x++){
			for(int l=0;l<s[x];l++){
				sum+=b[l][2][x];
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
