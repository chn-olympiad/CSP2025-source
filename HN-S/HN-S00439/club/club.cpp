#include<bits/stdc++.h>
using namespace std;
int a[100020],aq[100020],aw[100020];
int x,n;
int zq = 0,zw = 0,ze = 0,xq = 0,xw =0,xe =0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>x;
	for(int i =1;i<=x;i++){
		cin>>n;
		for(int j = 1;j<=n;j++){
			cin>>a[j]>>aq[j]>>aw[j]; 
		}
		for(int j = 1;j<=n;j++){
			if(zq<=n/2||zw<=n/2||ze<=n/2){
				if(a[j]>=aq[j]||a[j]>=aw[j]){
				zq++;
				xq+=a[j];
			}else if(aq[j]>=a[j]||aq[j]>=aw[j]){
				zw++;
				xw+=aq[j];
			}else if(aw[j]>=a[j]||aw[j]>=aq[j]){
				ze++;
				xe+=aw[j];
			}
		}else if(zw<=n/2||ze<=n/2){
			if(aq[j]>=a[j]||aq[j]>=aw[j]){
				zw++;
				xw+=aq[j];
			}else if(aw[j]>=a[j]||aw[j]>=aq[j]){
				ze++;
				xe+=aw[j];
			}
		}else if(ze<=n/2){
				ze++;
				xe+=aw[j];
		}
}
		cout<<xq+xw+xe<<endl;
		zq = 0,zw = 0,ze = 0,xq = 0,xw =0,xe =0;
	
	}
	return 0;
}
