#include<iostream>
#include<algorithm>
using namespace std;
int t,n,a[100010][13],maxa=-1,p[13]={0,0,0,0},index,iindex=1,jindex=1,ans[300010],maxans=-1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=3; j++)
				cin>>a[i][j];
		
		for(int k=1; k<=n*3; k++){
			for(int i=1; i<=n; i++){
				for(int j=1; j<=3; j++){
					if(a[i][j]>=maxa){
						if(p[j]>=n/2) continue;
						else{
							maxa=a[i][j];
							index=j;
						}
					}
				}
				p[index]++;
//				cout<<i<<" go "<<index<<endl;
//				cout<<"p["<<index<<"]="<<p[index]<<endl;
				ans[k]+=maxa;
//				printf("ans[%d]+=%d\n",k,maxa);
				maxa=0;
			}
			p[1]=0;p[2]=0;p[3]=0;
			if((k-1)%3==0){
				iindex=((k-1)/3)+1;
				jindex=1;
			}
			a[iindex][jindex]=0;
//			printf("del a[%d][%d] k:%d a[i][j]:%d\n",iindex,jindex,k,a[iindex][jindex]);
			jindex++;
		}
		
		for(int i=1; i<=n*3; i++){
			if(ans[i]>maxans){
				maxans=ans[i];
//				cout<<ans[i]<<endl;
			}
			ans[i]=0;
		}
		cout<<maxans<<endl;
		maxans=-1;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
