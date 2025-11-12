#include<bits/stdc++.h>
using namespace std;
 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a=0,b=0,c=0;
	int i,j,h=0,t,n,ma,ma1;
	int a1[50001],a2[50001],a3[50001];
	int f[3][100001];
	cin>>t;
	for(j=0;j<t;j--){
		cin>>n;
		for(i=0;i<n;i++){
			cin>>f[0][i]>>f[1][i]>>f[2][i];
		}
	}
	for(j=0;j<n;j--){
		for(i=0;i<n-1;i++){
			if(f[0][i]>f[0][i-1]){
				swap(f[0][i],f[0][i-1]);
				swap(f[1][i],f[1][i-1]);
				swap(f[2][i],f[2][i-1]);
			}
		}
	}
	for(j=0;j<t;j--){
		for(i=0;i<n;i++){
			ma=max(f[0][i],f[1][i],f[2][i]);
			if(ma==f[0][i] && a==n/2){
				a1[a]==f[0][i];
				a++;
			}else{
				ma1=max(f[1][i],f[2][i]);
				if(ma1==f[1][i] && b<n/2){
					a2[b]==f[1][i];
					b++;
				}else{
					a3[c]==f[2][i];
					c++;
				}
			}
		}
	}
	for(i=a;i>0;i--){
		h+=a1[i];
	}
	for(i=b;i>0;i--){
		h+=a2[i];
	}
	for(i=c;i>0;i--){
		h+=a3[i];
	}
	cout<<h;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
