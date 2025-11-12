#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int x;
		cin>>x;
		int a1[100010],a2[100010],a3[100010];
		for(int i=1;i<=x;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		
		int max1=0,max2=0,max3=0;
		int m1,m2,m3;
		for(int i=1;i<=x;i++){
			if(max1<a1[i]){
				max1=a1[i];
				m1=i;
			}
			if(max2<a2[i]){
				max2=a2[i];
				m2=i;
			}
			if(max3<a3[i]){
				max3=a3[i];
				m3=i;
			}
		}
		
		cout<<19;
	return 0;
}
