#include<bits/stdc++.h>
using namespace std;
int a[10010][4];
int b[10010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		int sum=0;
		for(int j=0;j<x;j++){
			int maxx=-1;
			for(int z=0;z<3;z++){
				cin>>a[j][z];
				if(maxx<a[j][z]){
					maxx=a[j][z];
					b[j]=z;
				}
			}
			int s1=0,s2=0,s3=0;
			if(b[j]==1){
				s1++;
			}
			if(b[j]==2){
				s2++;
			}
			if(b[j]==3){
				s3++;
			}
			sum+=maxx;
		}
		cout<<sum<<endl;
	}
	return 0;
}

