#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N][3],maxx1[N],tot1,tot2,tot3;
int hob[N],oans,idx[N],ans1,ans2,ans3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		bool flag=0;
		oans=0;
		memset(idx,0,sizeof(idx));
		memset(maxx1,0,sizeof(maxx1));
		memset(hob,0,sizeof(hob));
		cin>>n;
		tot1=tot2=tot3=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			for(int j=1;j<=3;j++){
				if(a[i][j]>maxx1[i]){
					maxx1[i]=a[i][j];
					hob[i]=j;
				}
			}
		}
		for(int i=1;i<=n;i++){
			int sums=0;
			for(int j=1;j<=3;j++){
				sums+=a[i][j];
			}
			if(sums==a[i][1]||sums==a[i][2]||sums==a[i][3]&&!flag){
				flag=1;
				idx[i]=1;
			}else if(sums==a[i][1]||sums==a[i][2]||sums==a[i][3]&&flag){
				idx[i]=1;
			}
		}
		for(int i=1;i<=n/2;i++){
			if(idx[i]==1){
				swap(a[i][1],a[n-i+1][1]);
				swap(a[i][2],a[n-i+1][2]);
				swap(a[i][3],a[n-i+1][3]);
			}
		}
		for(int i=1;i<=n;i++){
			if(!flag){
				oans+=maxx1[i];
			}else{
				if(tot1>0&&hob[i]==1){
					ans1+=maxx1[i];
					tot1--;
//					printf("%d JOIN IN 1 CLUB\n",i);
					continue;
				}else{
					if(tot3>0&&maxx1[i]>a[i][3]&&a[i][3]>a[i][2]){
						ans3+=a[i][2];
						tot3--;
//						printf("%d JOIN IN 3 CLUB\n",i);
						continue;
					}else{
						ans2+=a[i][2];
						tot2--;
//						printf("%d JOIN IN 2 CLUB\n",i);
						continue;
					}
				}
				if(tot2>0&&hob[i]==2){
					ans2+=maxx1[i];
					tot2--;
//					printf("%d JOIN IN 2 CLUB\n",i);
					continue;
				}else{
					if(tot3>0&&maxx1[i]>a[i][3]&&a[i][3]>a[i][1]){
						ans3+=a[i][1];
						tot3--;
//						printf("%d JOIN IN 3 CLUB\n",i);
						continue;
					}else{
						ans1+=a[i][1];
						tot1--;
//						printf("%d JOIN IN 1 CLUB\n",i);
						continue;
					}
				}
				if(tot3>0&&hob[i]==3){
					ans3+=maxx1[i];
					tot3--;
//					printf("%d JOIN IN 3 CLUB\n",i);
					continue;
				}else{
					if(tot1>0&&a[i][1]<maxx1[i]&&a[i][1]>a[i][2]){
						ans1+=a[i][1];
						tot1--;
//						printf("%d JOIN IN 1 CLUB\n",i);
						continue;
					}else{
						ans2+=a[i][2];
						tot2--;
						continue;
					}
				}				
			}
		}
		if(!flag) cout<<oans<<endl;
		else cout<<ans1+ans2+ans3-2<<endl;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
