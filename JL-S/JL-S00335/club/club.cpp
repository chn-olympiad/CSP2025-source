#include<bits/stdc++.h>
using namespace std;
#define N 10001
int a[N],b[N],c[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int z;
	cin>>z;
	for(int o=0;o<z;o++){
		
		int n;
		cin>>n;
		int acnt=0,bcnt=0;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
			acnt=acnt+a[i];
			}
			for(int j=0;j<n/2;j++){
				int cnt=1000000,cut;
				for(int i=0;i<n;i++){
					if(a[i]<cnt){
						cnt=a[i];
						cut=b[i];
					}
				}
				acnt=acnt-cnt;
				bcnt=cut+bcnt;
			}
			cout<<acnt+bcnt;
		
	}
	return 0;
}
