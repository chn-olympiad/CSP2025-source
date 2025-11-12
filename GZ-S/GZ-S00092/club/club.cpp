//GZ-S00092 中央民族大学附属中学贵阳学校 吴玅君 
#include<bits/stdc++.h>
using namespace std;
//forompen<"club.in",stdin>;
//forompen<"club.out",stdout>;
int main(){
	int q;
	cin>>q;
	while(q--){
		int n;
		cin>>n;
		int a[100005][5];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		int t1=0,t2=0,t3=0,p1=0,p2=0,p3=0;
		for(int i=1;i<=n;i++){
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]&&t1<n/2){
				p1+=a[i][1];t1++;
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]&&t2<n/2){
				p2+=a[i][2];t2++;
			}else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]&&t3<n/2){
				p3+=a[i][3];t3++;
			}else if(a[i][1]>=a[i][2]||a[i][1]>=a[i][3]&&t1<n/2){
				p1+=a[i][1];t1++;
			}else if(a[i][2]>=a[i][1]||a[i][2]>=a[i][3]&&t2<n/2){
				p2+=a[i][2];t2++;
			}else if(a[i][3]>=a[i][1]||a[i][3]>=a[i][2]&&t3<n/2){
				p3+=a[i][3];t3++;
			}
		}
		cout<<p1+p2+p3<<endl;
	}
	return 0;
}


