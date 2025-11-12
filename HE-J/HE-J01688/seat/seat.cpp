//B站关注MC_Chenzhao
//我的QQ是 1840326991
#include<bits/stdc++.h>
using namespace std;
struct ccf{
	int score;
	bool isChenzhao;
	int n,m; 
};
bool cmp(ccf a,ccf b){
	return a.score>b.score;
}
int main(){ 
	freopen("seat2.in","r",stdin);
	freopen("seat2.out","w",stdout);
	ofstream out;
	int n,m;
	cin>>n>>m;
	ccf a[50000];
	a[0].isChenzhao=true;
	int cnt=0;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			cin>>a[cnt].score;
			a[cnt].n=i;
			a[cnt].m=j;
			cnt++;
		}
	}
	sort(a,a+(n*m),cmp);
	cnt=0;
	cnt=0;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){	
			if(a[cnt].isChenzhao){
				if(not(a[cnt].n&1)){
					int a1[m+1];
					for(int i = 0;i<m;i++){
						a1[i]=i+1;
						
					}
					reverse(a1,a1+m);

					cout<<i+1<<" "<<a1[j];
					return 0;
				}
				else{

					cout<<i+1<<' '<<j+1;
					return 0;
				}
			}cnt++;
		}
	}
	return 0;
}








































 
